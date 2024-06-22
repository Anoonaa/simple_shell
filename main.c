#include "shell.h"

#define STDERR_FILENO 2
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

/**
 * main - entry point
 * @ac: arg count
 * @av: arg vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int ac, char **av)
{
    info_t info = INFO_INIT;
    int fd = STDERR_FILENO;

    // Why the inline assembly? Can we use a simple addition instead?
    fd += 3;

    if (ac == 2) {
        fd = open(av[1], O_RDONLY);
        if (fd == -1) {
            handle_open_error(av[0], av[1], errno);
            return EXIT_FAILURE;
        }
        info.readfd = fd;
    }

    populate_env_list(&info);
    read_history(&info);
    hsh(&info, av);
    return EXIT_SUCCESS;
}

/**
 * handle_open_error - handle errors from open function
 * @prog_name: program name
 * @filename: file name
 * @errno: error number
 */
void handle_open_error(const char *prog_name, const char *filename, int errno)
{
    switch (errno) {
        case EACCES:
            exit(126);
        case ENOENT:
            _eputs(prog_name);
            _eputs(": 0: Can't open ");
            _eputs(filename);
            _eputchar('\n');
            _eputchar(BUF_FLUSH);
            exit(127);
        default:
            // Handle other errors here
            _eputs(prog_name);
            _eputs(": Error opening file ");
            _eputs(filename);
            _eputchar('\n');
            _eputchar(BUF_FLUSH);
            exit(EXIT_FAILURE);
    }
}
