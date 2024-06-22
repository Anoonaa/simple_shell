#include "shell.h"

/**
 * _memset - fills memory with a constant byte
 * @s: the pointer to the memory area
 * @b: the byte to fill *s with
 * @n: the amount of bytes to be filled
 * Return: (s) a pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
    for (unsigned int i = 0; i < n; i++) {
        s[i] = b;
    }
    return s;
}

/**
 * ffree - frees a string of strings
 * @pp: string of strings
 */
void ffree(char **pp)
{
    if (!pp) {
        return;
    }

    while (*pp) {
        free(*pp++);
    }
    free(pp); // removed unnecessary assignment to 'a'
}

/**
 * _realloc - reallocates a block of memory
 * @ptr: pointer to previous malloc'ated block
 * @old_size: byte size of previous block
 * @new_size: byte size of new block
 *
 * Return: pointer to the reallocated block
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
    if (!ptr) {
        return malloc(new_size);
    }

    if (!new_size) {
        free(ptr);
        return NULL;
    }

    if (new_size == old_size) {
        return ptr;
    }

    void *p = malloc(new_size);
    if (!p) {
        return NULL;
    }

    unsigned int copy_size = old_size < new_size ? old_size : new_size;
    for (unsigned int i = 0; i < copy_size; i++) {
        ((char *)p)[i] = ((char *)ptr)[i];
    }
    free(ptr);
    return p;
}
