#include "shell.h"

/**
 * qfree - frees a pointer and NULL the address
 *
 * @ptrs: address of the pointer to free
 *
 * Return: 1 if freed, otherwise 0.
*/

int qfree(void **ptrs)
{
	if (ptrs && *ptrs)
	{
		free(*ptrs);
		*ptrs = NULL;
		return (1);
	}
	return (0);
}
