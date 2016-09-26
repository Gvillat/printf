#include "../includes/ft_printf.h"

size_t		ft_wstrlen(wchar_t *s)
{
	ssize_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}