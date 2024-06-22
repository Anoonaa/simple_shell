#include "shell.h"

/**
 * strtow - splits a string into words. Repeat delimiters are ignored
 * @str: the input string
 * @d: the delimiter string
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow(char *str, char *d)
{
    int i, num_words = 0;
    char **s;

    if (!str || !*str)
        return (NULL);
    if (!d)
        d = " ";

    for (i = 0; str[i]; i++)
        if (!is_delim(str[i], d) && (is_delim(str[i + 1], d) || !str[i + 1]))
            num_words++;

    if (num_words == 0)
        return (NULL);

    s = malloc((num_words + 1) * sizeof(char *));
    if (!s)
        return (NULL);

    for (i = 0, num_words = 0; *str; str++)
    {
        while (is_delim(*str, d))
            str++;
        int word_len = 0;
        while (*str && !is_delim(*str, d))
            word_len++, str++;
        s[num_words] = malloc((word_len + 1) * sizeof(char));
        if (!s[num_words])
        {
            for (i = 0; i < num_words; i++)
                free(s[i]);
            free(s);
            return (NULL);
        }
        for (int j = 0; j < word_len; j++)
            s[num_words][j] = *(str - word_len + j);
        s[num_words][word_len] = 0;
        num_words++;
    }
    s[num_words] = NULL;
    return (s);
}

/**
 * strtow2 - splits a string into words
 * @str: the input string
 * @d: the delimiter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *str, char d)
{
    int i, num_words = 0;
    char **s;

    if (!str || !*str)
        return (NULL);

    for (i = 0; str[i]; i++)
        if ((str[i] != d && str[i + 1] == d) ||
            (str[i] != d && !str[i + 1]) || str[i + 1] == d)
            num_words++;

    if (num_words == 0)
        return (NULL);

    s = malloc((num_words + 1) * sizeof(char *));
    if (!s)
        return (NULL);

    for (i = 0, num_words = 0; *str; str++)
    {
        while (*str == d)
            str++;
        int word_len = 0;
        while (*str && *str != d)
            word_len++, str++;
        s[num_words] = malloc((word_len + 1) * sizeof(char));
        if (!s[num_words])
        {
            for (i = 0; i < num_words; i++)
                free(s[i]);
            free(s);
            return (NULL);
        }
        for (int j = 0; j < word_len; j++)
            s[num_words][j] = *(str - word_len + j);
        s[num_words][word_len] = 0;
        num_words++;
    }
    s[num_words] = NULL;
    return (s);
}
