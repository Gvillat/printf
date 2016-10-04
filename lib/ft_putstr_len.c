#include <../includes/ft_printf.h>

void	ft_putstr_len(char *s, ssize_t len)
{
	ssize_t	i;

	i = 0;
	while (s[i] && i < len)
	{
		ft_buff(&s[i]);
		i++;
	}
}