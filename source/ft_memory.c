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
	argument->zeropadding = 0;
	argument->rightpadding = 1;
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
	spe->spe['p'] = pointer_handler;
	spe->spe['s'] = string_handler;
	spe->spe['S'] = string_handler;
	spe->spe['c'] = character_handler;
	spe->spe['C'] = character_handler;
	spe->spe['d'] = signed_handler;
	spe->spe['D'] = signed_handler;
	spe->spe['i'] = signed_handler;
	spe->spe['o'] = unsigned_handler;
	spe->spe['O'] = unsigned_handler;
	spe->spe['u'] = unsigned_handler;
	spe->spe['U'] = unsigned_handler;
	spe->spe['%'] = prc_handler;
	spe->spe['x'] = unsigned_handler;
	spe->spe['X'] = unsigned_handler;
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