#include "shell.h"

/**
 * is_cmd - determines if a file is an executable command
 *
 * @inf: the info struct
 * @pth: path to the file
 *
 * Return: 1 if true, 0 otherwise
*/
int is_cmd(info_t *inf, char *pth)
{
	struct stat st;

	(void)inf;
	if (!pth || stat(pth, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - duplicates characters
 *
 * @pthstr: the PATH string
 * @start: starting index
 * @stop: stopping index
 *
 * Return: pointer to new buffer
 */

char *dup_chars(char *pthstr, int strt, int stp)
{
	static char buf[1024];
	int i = 0, j = 0;

	for (j = 0, i = strt; i < stp; i++)
		if (pthstr[i] != ':')
			buf[j++] = pthstr[i];
	buf[j] = 0;
	return (buf);
}

/**
 * find_path - finds this cmd in the PATH string
 *
 * @info: the info struct
 * @pathstr: the PATH string
 * @cmd: the cmd to find
 *
 * Return: full path of cmd if found or NULL
 */

char *find_path(info_t *info, char *pthstr, char *cmd)
{
	int i = 0, curr_pos = 0;
	char *pth;

	if (!pthstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pthstr[i] || pthstr[i] == ':')
		{
			pth = dup_chars(pthstr, curr_pos, i);
			if (!*pth)
				_strcat(pth, cmd);
			else
			{
				_strcat(pth, "/");
				_strcat(pth, cmd);
			}
			if (is_cmd(info, pth))
				return (pth);
			if (!pthstr[i])
				break;
			curr_pos = i;
		}
		i++;
	}
	return (NULL);
}
