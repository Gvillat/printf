#include "includes/ft_printf.h"

int		ft_check_width(PF *chibre)
{
	int		i;
	char	*str;

	i = chibre->index;
	if (ft_isdigit(chibre->format[chibre->index]) && chibre->format[chibre->index] != '0')
	{
		while (ft_isdigit(chibre->format[chibre->index]))
			chibre->index++;
		if (chibre->index - i > 0)
		{
			chibre->flags[1] = 0;
			str = ft_strsub(chibre->format, i, chibre->index - i);
			chibre->flags[1] = ft_atoi((const char*)str);
			free(str);
		}
	}
	return(chibre->index);
}

int		ft_check_precision(PF *chibre)
{
	int		i;
	char	*str;

	if (chibre->format[chibre->index] == '.')
	{
		i = ++chibre->index;
		while (ft_isdigit(chibre->format[chibre->index]))
			chibre->index++;
		if (chibre->index - i > 0)
		{
			str = ft_strsub(chibre->format, i, chibre->index - i);
			chibre->flags[0] = ft_atoi((const char*)str);
			free(str);
		}
	}
	return(chibre->index);
}

int ft_check_flags(PF *chibre)
{
	while (chibre->format[chibre->index] == '-' || chibre->format[chibre->index] == '+' || chibre->format[chibre->index] == ' ' || chibre->format[chibre->index] == '#' || chibre->format[chibre->index] == '0')
	{
		if (chibre->format[chibre->index] == '#')
			chibre->flags[2] = 1;
		if (chibre->format[chibre->index] == '0')
			chibre->flags[3] = 1;
		if (chibre->format[chibre->index] == '-')
			chibre->flags[4] = 1;
		if (chibre->format[chibre->index] == '+')
			chibre->flags[5] = 1;
		if (chibre->format[chibre->index] == ' ')
			chibre->flags[6] = 1;
		chibre->index++;
	}
	return(chibre->index);
}

int ft_check_length(PF *chibre)
{
	while (chibre->format[chibre->index] == 'h' || chibre->format[chibre->index] == 'l'
		|| chibre->format[chibre->index] == 'z' || chibre->format[chibre->index] == 'j')
	{
		if (chibre->format[chibre->index] == 'z')
			chibre->flags[12] = 1;
		else if (chibre->format[chibre->index] == 'j')
			chibre->flags[11] = 1;
		else if (chibre->format[chibre->index] == 'h' && chibre->format[chibre->index + 1] == 'h')
		{
			chibre->flags[7] = 1;
			chibre->index++;
		}
		else if (chibre->format[chibre->index] == 'h')
			chibre->flags[8] = 1;
		else if (chibre->format[chibre->index] == 'l' && chibre->format[chibre->index + 1] == 'l')
		{
			chibre->flags[9] = 1;
			chibre->index++;
		}
		else if (chibre->format[chibre->index] == 'l')
			chibre->flags[10] = 1;
		chibre->index++;
	}
	return(chibre->index);
}

int ft_check_spec(PF *chibre)
{
	if (chibre->format[chibre->index] == 's')
		chibre->spec = 's';
	else if (chibre->format[chibre->index] == 'S')
		chibre->spec = 'S';
	else if (chibre->format[chibre->index] == 'p')
		chibre->spec = 'p';
	else if (chibre->format[chibre->index] == 'd')
		chibre->spec = 'd';
	else if (chibre->format[chibre->index] == 'D')
		chibre->spec = 'D';
	else if (chibre->format[chibre->index] == 'i')
		chibre->spec = 'i';
	else if (chibre->format[chibre->index] == 'o')
		chibre->spec = 'o';
	else if (chibre->format[chibre->index] == 'O')
		chibre->spec = 'O';
	else if (chibre->format[chibre->index] == 'u')
		chibre->spec = 'u';
	else if (chibre->format[chibre->index] == 'U')
		chibre->spec = 'U';
	else if (chibre->format[chibre->index] == 'x')
		chibre->spec = 'x';
	else if (chibre->format[chibre->index] == 'X')
		chibre->spec = 'X';
	else if (chibre->format[chibre->index] == 'c')
		chibre->spec = 'c';
	else if(chibre->format[chibre->index] == 'C')
		chibre->spec = 'C';
	return(chibre->index);
}

int ft_get_flags(PF *chibre, va_list ap)
{
	chibre->index = 0;
	while (chibre->format[chibre->index] == '#' || chibre->format[chibre->index] == '0'
		|| chibre->format[chibre->index] == '-' || chibre->format[chibre->index] == '+'
		|| chibre->format[chibre->index] == ' ' || chibre->format[chibre->index] == 'h'
		|| chibre->format[chibre->index] == 'l' || chibre->format[chibre->index] == 'j'
		|| chibre->format[chibre->index] == 'z' || chibre->format[chibre->index] == '.'
		|| chibre->format[chibre->index] == '*' || ft_isdigit(chibre->format[chibre->index]))
	{
		ft_check_flags(chibre);
		ft_check_width(chibre);
		ft_check_precision(chibre);
		ft_check_length(chibre);
	}
	ft_check_spec(chibre);
	chibre->spec = chibre->format[chibre->index];
	if (chibre->index == ft_strlen(chibre->format))
		return (-1);
	return (chibre->index);
}
