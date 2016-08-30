#include "includes/ft_printf.h"

PF *ft_init_chibre(PF *chibre)
{
	int i;

	i = 0;
	while (i < 13)
	{
		chibre->flags[i] = 0;
		i++;
	}
	chibre->format = NULL;
	chibre->index = 0;
	chibre->spec = '\0';
	chibre->arg = NULL;
	return (chibre);
}

// void ft_init_spe_tab(SPE *spe)
// {
// 	spe['s'].ptr = &ft_arg_s;
// 	spe['S'].ptr = &ft_arg_ups;
// 	spe['c'].ptr = &ft_arg_c;
// 	spe['C'].ptr = &ft_arg_upc;
// 	spe['d'].ptr = &ft_arg_d;
// 	spe['D'].ptr = &ft_arg_upd;
// 	spe['i'].ptr = &ft_arg_d;
// 	spe['o'].ptr = &ft_arg_o;
// 	spe['O'].ptr = &ft_arg_upo;
// 	spe['u'].ptr = &ft_arg_u;
// 	spe['U'].ptr = &ft_arg_upu;
// 	spe[' '].ptr = &ft_arg_nospe;
// }

// int ft_get_arg(PF *chibre, va_list ap, SPE *spe)
// {
// 	void *arg;
// 	chibre->arg = spe[chibre->spec];

// 	return(chibre->index);
// }

int ft_check_format(char *str, PF *chibre, va_list ap)
{
	int i;
	SPE spe[128];

	i = -1;
	// ft_init_spe_tab(spe);
	while (str[++i] != '\0')
	{
		if (str[i] == '%')
		{
			ft_init_chibre(chibre);
			chibre->format = &str[++i];
			if (ft_get_flags(chibre, ap) == -1)
				break;
			// ft_get_arg(chigbre, ap, spe);
			i += chibre->index;
		}
		else if (str[i] != '%' && str[i] != '\0')
		{
			g_buff[g_i] = str[i];
			g_i++;
		}
	}
	return(0);
}



int ft_printf(const char *format, ...)
{
	va_list ap;
	PF chibre;

	chibre.ret = 0;
	if (!format)
		return(0);
	va_start(ap, format);
	ft_init_buff();
	ft_check_format((char*)format, &chibre, ap);
	if (g_i)
		ft_display(&chibre);
	ft_putchar('\n');
	va_end(ap);
	return(chibre.ret);
}

int main(int ac, char **av)
{  
	char *s, c, d;
	int a;

	a = 42;
	s = "chibre";
	c = 55;
	d = 'q';

	ft_printf(av[1], a, s, c, d);
	// ft_printf("%c test2", d);
	// ft_printf("te %c st3", c);
	// ft_printf("%s", s);
	return (0);
}
			// printf("G_BUFF: %s\n",g_buff );
			// printf("SPECIFIER %c\n", chibre->spec);
			// printf("FLAGS: precision=%d  width=%d  #=%d  0=%d  -=%d  +=%d  space=%d  hh=%d  h=%d  ll=%d  l=%d  j=%d  z=%d\n",chibre->flags[0], chibre->flags[1], chibre->flags[2], chibre->flags[3], chibre->flags[4], chibre->flags[5], chibre->flags[6], chibre->flags[7], chibre->flags[8], chibre->flags[9], chibre->flags[10], chibre->flags[11], chibre->flags[12]);

			// printf("Format: %s\n",chibre.format);
			// chibre.format = &str[++i];
			// chibre.index = i;
			// printf("index = %d                                 i = %d  \n",chibre.index, i );
			// printf("format = %s                                g_buff = %s\n",chibre.format , g_buff);
			// // if (ft_get_flags(chibre, str) == -1)