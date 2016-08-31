#include "includes/ft_printf.h"

int		ft_check_width(PF *argument)
{
	int		i;
	char	*str;

	i = argument->index;
	if (ft_isdigit(argument->format[argument->index]) && argument->format[argument->index] != '0')
	{
		while (ft_isdigit(argument->format[argument->index]))
			argument->index++;
		if (argument->index - i > 0)
		{
			argument->flags[1] = 0;
			str = ft_strsub(argument->format, i, argument->index - i);
			argument->flags[1] = ft_atoi((const char*)str);
			free(str);
		}
	}
	return(argument->index);
}

int		ft_check_precision(PF *argument)
{
	int		i;
	char	*str;

	if (argument->format[argument->index] == '.')
	{
		i = ++argument->index;
		while (ft_isdigit(argument->format[argument->index]))
			argument->index++;
		if (argument->index - i > 0)
		{
			str = ft_strsub(argument->format, i, argument->index - i);
			argument->flags[0] = ft_atoi((const char*)str);
			free(str);
		}
	}
	return(argument->index);
}

int ft_check_flags(PF *argument)
{
	while (argument->format[argument->index] == '-' || argument->format[argument->index] == '+' || argument->format[argument->index] == ' ' || argument->format[argument->index] == '#' || argument->format[argument->index] == '0')
	{
		if (argument->format[argument->index] == '#')
			argument->flags[2] = 1;
		if (argument->format[argument->index] == '0')
			argument->flags[3] = 1;
		if (argument->format[argument->index] == '-')
			argument->flags[4] = 1;
		if (argument->format[argument->index] == '+')
			argument->flags[5] = 1;
		if (argument->format[argument->index] == ' ')
			argument->flags[6] = 1;
		argument->index++;
	}
	return(argument->index);
}

int ft_check_length(PF *argument)
{
	while (argument->format[argument->index] == 'h' || argument->format[argument->index] == 'l'
		|| argument->format[argument->index] == 'z' || argument->format[argument->index] == 'j')
	{
		if (argument->format[argument->index] == 'z')
			argument->flags[12] = 1;
		else if (argument->format[argument->index] == 'j')
			argument->flags[11] = 1;
		else if (argument->format[argument->index] == 'h' && argument->format[argument->index + 1] == 'h')
		{
			argument->flags[7] = 1;
			argument->index++;
		}
		else if (argument->format[argument->index] == 'h')
			argument->flags[8] = 1;
		else if (argument->format[argument->index] == 'l' && argument->format[argument->index + 1] == 'l')
		{
			argument->flags[9] = 1;
			argument->index++;
		}
		else if (argument->format[argument->index] == 'l')
			argument->flags[10] = 1;
		argument->index++;
	}
	return(argument->index);
}

int ft_check_spec(PF *argument)
{
	if (argument->format[argument->index] == 's')
		argument->spec = 's';
	else if (argument->format[argument->index] == 'S')
		argument->spec = 'S';
	else if (argument->format[argument->index] == 'p')
		argument->spec = 'p';
	else if (argument->format[argument->index] == 'd')
		argument->spec = 'd';
	else if (argument->format[argument->index] == 'D')
		argument->spec = 'D';
	else if (argument->format[argument->index] == 'i')
		argument->spec = 'i';
	else if (argument->format[argument->index] == 'o')
		argument->spec = 'o';
	else if (argument->format[argument->index] == 'O')
		argument->spec = 'O';
	else if (argument->format[argument->index] == 'u')
		argument->spec = 'u';
	else if (argument->format[argument->index] == 'U')
		argument->spec = 'U';
	else if (argument->format[argument->index] == 'x')
		argument->spec = 'x';
	else if (argument->format[argument->index] == 'X')
		argument->spec = 'X';
	else if (argument->format[argument->index] == 'c')
		argument->spec = 'c';
	else if(argument->format[argument->index] == 'C')
		argument->spec = 'C';
	else
		argument->spec = argument->format[argument->index];
	return(argument->index);
}

int ft_get_flags(PF *argument, va_list ap)
{
	argument->index = 0;
	while (argument->format[argument->index] == '#' || argument->format[argument->index] == '0'
		|| argument->format[argument->index] == '-' || argument->format[argument->index] == '+'
		|| argument->format[argument->index] == ' ' || argument->format[argument->index] == 'h'
		|| argument->format[argument->index] == 'l' || argument->format[argument->index] == 'j'
		|| argument->format[argument->index] == 'z' || argument->format[argument->index] == '.'
		|| argument->format[argument->index] == '*' || ft_isdigit(argument->format[argument->index]))
	{
		ft_check_flags(argument);
		ft_check_width(argument);
		ft_check_precision(argument);
		ft_check_length(argument);
	}
	ft_check_spec(argument);
	printf("SPECIFIER %c\n",argument->spec );
	if (argument->index == ft_strlen(argument->format))
		return (-1);
	return (argument->index);
}
