#include "shell.h"

/**
 * is_chain - Tests if the current character in the buffer is a chain delimiter.
 * @info: The parameter structure.
 * @buf: The character buffer.
 * @p: Address of the current position in buf.
 *
 * Return: 1 if the character is a chain delimiter, 0 otherwise.
 */
int is_chain(info_t *info, char *buf, size_t *p) {
    size_t j = *p;

    if (buf[j] == '|' && buf[j + 1] == '|') {
        buf[j] = '\0';
        j++;
        info->cmd_buf_type = CMD_OR;
    } else if (buf[j] == '&' && buf[j + 1] == '&') {
        buf[j] = '\0';
        j++;
        info->cmd_buf_type = CMD_AND;
    } else if (buf[j] == ';') {
        buf[j] = '\0'; /* Replace semicolon with null */
        info->cmd_buf_type = CMD_CHAIN;
    } else {
        return 0;
    }
    *p = j;
    return 1;
}

/**
 * check_chain - Checks if we should continue chaining based on the last status.
 * @info: The parameter structure.
 * @buf: The character buffer.
 * @p: Address of the current position in buf.
 * @i: Starting position in buf.
 * @len: Length of buf.
 *
 * Return: Nothing (void).
 */
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len) {
    size_t j = *p;

    if (info->cmd_buf_type == CMD_AND) {
        if (info->status) {
            buf[i] = '\0';
            j = len;
        }
    } else if (info->cmd_buf_type == CMD_OR) {
        if (!info->status) {
            buf[i] = '\0';
            j = len;
        }
    }

    *p = j;
}

/**
 * replace_alias - Replaces an alias in the tokenized string.
 * @info: The parameter structure.
 *
 * Return: 1 if an alias was replaced, 0 otherwise.
 */
int replace_alias(info_t *info) {
    int i;
    list_t *node;
    char *p;

    for (i = 0; i < 10; i++) {
        node = node_starts_with(info->alias, info->argv[0], '=');
        if (!node) {
            return 0;
        }
        free(info->argv[0]);
        p = strchr(node->str, '=');
        if (!p) {
            return 0;
        }
        p = strdup(p + 1);
        if (!p) {
            return 0;
        }
        info->argv[0] = p;
    }
    return 1;
}

/**
 * replace_vars - Replaces variables in the tokenized string.
 * @info: The parameter structure.
 *
 * Return: 1 if a variable was replaced, 0 otherwise.
 */
int replace_vars(info_t *info) {
    int i = 0;
    list_t *node;

    for (i = 0; info->argv[i]; i++) {
        if (info->argv[i][0] != '<span class="math-inline">' \|\| \!info\-\>argv\[i\]\[1\]\) \{
continue;
\}
if \(\!strcmp\(info\-\>argv\[i\], "</span>?")) {
            replace_string(&info->argv[i], strdup(convert_number(info->status, 10, 0)));
            continue;
        }
        if (!strcmp(info->argv[i], "$$")) {
            replace_string(&info->argv[i], strdup(convert_number(getpid(), 10, 0)));
            continue;
        }
        node = node_starts_with(info->env, &info->argv[i][1], '=');
        if (node) {

