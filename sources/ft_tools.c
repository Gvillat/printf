#include "../includes/ft_ls.h"

char		*tool_checkdirname(char *dir)
{
	if (dir == NULL)
		return (dir);
	if (dir[ft_strlen(dir) - 1] != '/')
		return (ft_strjoin(dir, "/"));
	return (dir);
}

int tool_stats(char *path)
{
	STAT st;

	if (lstat(path, &st) == -1)
	{
		perror("chibre ");
		exit(EXIT_FAILURE);
	}
	if (S_ISDIR(st.st_mode))
		return(1);
	return(0);
}
