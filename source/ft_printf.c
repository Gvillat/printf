#include "../includes/ft_printf.h"

void *ft_apply_width(void *args, PF *argument, va_list ap, int len)
{
	char str[argument->flags[1] + 1];
	int i;
	int j;

	i = 0;
	argument->arg = args;
	j = 0;
	if (argument->flags[4])
	{
		while (i < argument->flags[1])
		{
			if (argument->arg[j] != '\0')
			{
				str[i] = argument->arg[j];
				j++;
			}
			else
				str[i] = ' ';
			i++;
		}
	}
	else
	{
		if (argument->flags[3])
		{
			while (i < argument->flags[1] - len)
				str[i++] = '0';
			while (argument->arg[j] != '\0')
				str[i++] = argument->arg[j++];
		}
		else
		{
			while (i < argument->flags[1] - len)
				str[i++] = ' ';
			while (argument->arg[j] != '\0')
				str[i++] = argument->arg[j++];
		}
	}
	str[i] = '\0';
	argument->arg = str;
	return (argument->arg);
}

void ft_apply_sharp(void *args, PF *argument, va_list ap, int len)
{
	if ((argument->flags[2] && argument->spec == 'x') || argument->spec == 'p')
		ft_buff(argument, "0x");
	else if (argument->flags[2] && argument->spec == 'X')
		ft_buff(argument, "0X");
	else if (argument->flags[2] && (argument->spec == 'o' || argument->spec == 'O'))
		ft_buff(argument, "0");
}

void ft_apply_plus_and_space(void *args, PF *argument, va_list ap, int len)
{
	if (argument->flags[5] || argument->flags[6])
	{
		if (argument->spec == 'd' || argument->spec == 'D' || argument->spec == 'i')
		{
			if (argument->flags[6] == 1 && argument->flags[5] == 0 && (int)ap > 0)
				ft_buff(argument, " ");
			if (argument->flags[5] == 1 && (int)ap > 0)
				ft_buff(argument, "+");
		}
	}
	if (argument->signe == -1)
		ft_buff(argument, "-");
	ft_apply_sharp(args, argument, ap, len);
}

char *ft_apply_flags(void *args, PF *argument, va_list ap)
{
	int len;

	len = ft_strlen(args);
	ft_apply_plus_and_space(args, argument, ap, len);
	if (len < argument->flags[1] && argument->flags[1] > 0)
		args = ft_apply_width(args, argument, ap, len); // cree un champ si len < width et check les flags - 0 ' '
	// // check les flags # et -
	// check precisionpour sqvoir combien char argmettre
	return(ft_buff(argument, (char*)args));
}

int ft_check_format(char *str, PF *argument, va_list ap)
{
	int i;
	SPE spe[128];
	i = -1;
	ft_init_spe_tab(spe);
	while (str[++i] != '\0')
	{
		if (str[i] == '%')
		{
			ft_init_argument(argument);
			argument->format = &str[++i];
			if (ft_get_flags(argument, ap) == -1)
				return(-1);
			spe->spe[argument->spec](argument, va_arg(ap, void*));
			i += argument->index;
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
	PF argument;

	argument.ret = 0;
	if (!format)
		return(0);
	va_start(ap, format);
	ft_init_buff();
	ft_check_format((char*)format, &argument, ap);
	if (g_i)
		ft_display(&argument);
	ft_putchar('\n');
	va_end(ap);
	return(argument.ret);
}

int main(int ac, char **av)
{  
	char *s, c, d;
	int a, b;
	void *e;

	e = &a;
	b = -17865;
	a = -42;
	s = "argument";
	c = 55;
	d = 'q';

	ft_printf(av[1], a, b, c, d, s, e);
	printf("\n");
	printf(av[1], a, b, c, d, s, e);
	return (0);
}