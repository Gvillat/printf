#include "../includes/ft_printf.h"

PF *ft_init_argument(PF *argument)
{
	int i;

	i = 0;
	while (i < 13)
	{
		argument->flags[i] = 0;
		i++;
	}
	argument->format = NULL;
	argument->index = 0;
	argument->spec = ' ';
	argument->arg = NULL;
	argument->signe = 0;
	return (argument);
}

void ft_init_spe_tab(SPE *spe)
{
	int i;

	i = 0;
	while (i < 128)
	{
		spe->spe[i] = ft_arg_nospe;
		i++;
	}
	spe->spe['p'] = ft_arg_p;
	spe->spe['s'] = ft_arg_s;
	spe->spe['S'] = ft_arg_s;
	spe->spe['c'] = ft_arg_c;
	spe->spe['C'] = ft_arg_c;
	spe->spe['d'] = ft_arg_d;
	spe->spe['D'] = ft_arg_d;
	spe->spe['i'] = ft_arg_d;
	spe->spe['o'] = ft_arg_o;
	spe->spe['O'] = ft_arg_o;
	spe->spe['u'] = ft_arg_u;
	spe->spe['U'] = ft_arg_u;
	spe->spe['%'] = ft_arg_prc;
	spe->spe['x'] = ft_arg_x;
	spe->spe['X'] = ft_arg_x;
}

void ft_init_buff()
{
	int n;

	n = 0;
	while (n < 4096)
	{
		g_buff[n] = '\0';
		n++;
	}
	g_i = 0;
}