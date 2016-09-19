#include "../includes/ft_printf.h"

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