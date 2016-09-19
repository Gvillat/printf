#include "../includes/ft_printf.h"

void *ft_strlower(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] = ft_tolower(s[i]);
		i++; 
	}
	return(s);
}