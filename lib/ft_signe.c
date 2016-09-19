#include "../includes/ft_printf.h"

int ft_signe(int nbr, PF *argument)
{
	if (nbr < 0)
	{
		nbr = -nbr;
		argument->signe = -1;
	}
	else
		argument->signe = 1;
	return(nbr);
}