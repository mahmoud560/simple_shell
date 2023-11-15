#include "shell.h"

/**
 * _strlen - returns the length of a string
 *
 * @m: the string whose length to check
 *
 * Return: integer length of string
*/

int _strlen(char *m)
{
	int i = 0;

	if (!m)
		return (0);

	while (*m++)
		i++;
	return (i);
}

/**
 * _strcmp - performs lexicogarphic comparison of two strangs.
 *
 * @m1: the first strang
 * @m2: the second strang
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *m1, char *m2)
{
	while (*m1 && *m2)
	{
		if (*m1 != *m2)
			return (*m1 - *m2);
		m1++;
		m2++;
	}
	if (*m1 == *m2)
		return (0);
	else
		return (*m1 < *m2 ? -1 : 1);
}

/**
 * starts_with - checks if needle starts with haystack
 *
 * @haystack: string to search
 * @needle: the substring to find
 *
 * Return: address of next char of haystack or NULL
 */
char *starts_with(const char *hystack, const char *ndle)
{
	while (*ndle)
		if (*ndle++ != *hystack++)
			return (NULL);
	return ((char *)hystack);
}

/**
 * _strcat - concatenates two strings
 * @dest: the destination buffer
 * @src: the source buffer
 *
 * Return: pointer to destination buffer
 */

char *_strcat(char *dest, char *src)
{
	char *rt = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (rt);
}
