#include "includes/ft_printf.h"

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

int ft_display(PF *argument)
{
	argument->ret = write(1, &g_buff, g_i);
	return(argument->ret);
}

void *ft_buff(PF *argument, char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		g_buff[g_i] = str[i];
		i++;
		g_i++;
	}
	return(NULL);
}