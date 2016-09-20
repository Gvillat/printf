#include "../includes/ft_printf.h"

uintmax_t ft_signe(int nbr, PF *argument)
{
	argument->signe = 1;
	if (nbr < 0)
	{
		nbr = -nbr;
		argument->signe = -1;
	}
	return((intmax_t)nbr);
}