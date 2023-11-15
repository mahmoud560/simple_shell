#include "shell.h"

/**
 **_memset - fills memory with a constant byte
 *@t: the pointer to the memory area
 *@k: the byte to fill *s with
 *@n: the amount of bytes to be filled
 *Return: (s) a pointer to the memory area s
*/

char *_memset(char *t, char k, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		t[i] = k;
	return (t);
}

/**
 * ffree - frees a string of strings
 *
 * @rt: string of strings
*/

void ffree(char **rt)
{
	char **a = rt;

	if (!rt)
		return;
	while (*rt)
		free(*rt++);
	free(a);
}

/**
 * _realloc - reallocates a block of memory
 *
 * @ptr: pointer to previous malloc'ated block
 * @old_size: byte size of previous block
 * @new_size: byte size of new block
 *
 * Return: pointer to da ol'block nameen.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
