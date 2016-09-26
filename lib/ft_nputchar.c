#include "../includes/ft_printf.h"

void		ft_nputchar(PF *argument, char c, size_t n)
{
	size_t	i;
	char s[2];

	s[0] = c;
	s[1] = '\0';
	i = 0;
	while (i < n)
	{
		ft_buff(argument, s);
		i++;
	}
}