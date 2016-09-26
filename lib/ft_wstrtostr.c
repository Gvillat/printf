#include "../includes/ft_printf.h"

int		ft_wstrtostr(char *s, wchar_t *wstr, int n)
{
	int			i;
	int			tmp;
	int			len;

	len = 0;
	i = 0;
	while (wstr[i] != 0)
	{
		tmp = ft_wchartostr(s + len, wstr[i]);
		if ((tmp + len) > n)
			break ;
		len += tmp;
		i++;
	}
	return (len);
}