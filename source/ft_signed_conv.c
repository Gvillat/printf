/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signed_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 17:35:51 by gvillat           #+#    #+#             */
/*   Updated: 2016/09/27 17:35:53 by gvillat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static intmax_t		signed_cast(PF *argument, va_list ap)
{
	intmax_t	n;

	n = va_arg(ap, intmax_t);
	if (argument->flags[12] == 1)
		n = (size_t)n;
	else if (argument->flags[11] == 1)
		return (n);
	else if (argument->flags[9] == 1)
		n = (long long)n;
	else if (argument->flags[10] == 1)
		n = (long)n;
	else if (argument->flags[8] == 1)
		n = (short)n;
	else if (argument->flags[7] == 1)
		n = (char)n;
	else
		n = (int)n;
	return (n);
}

static char			*test_string(PF *args)
{
	int			octal;

	if (!args->arg)
		return (NULL);
	octal = 0;
	if (args->spec == 'o' || args->spec == 'O')
		octal = 1;
	if (ft_strcmp((const char *)args->arg, "0") == 0 && args->flags[0] == 0)
	{
		if (!octal || (octal && !args->flags[2]))
			return (ft_strdup(""));
	}
	return (args->arg);
}

int					signed_handler(PF *argument, va_list ap)
{
	intmax_t	n;

	n = 0;
	if (argument->spec == 'd' || argument->spec == 'i')
		n = signed_cast(argument, ap);
	else
		n = (long int)va_arg(ap, intmax_t);
	argument->arg = ft_itoa_base(n, 10);
	if (n < 0)
	{
		argument->arg = ft_itoa_base(-n, 10);
		return (ft_print_number(argument, "-"));
	}
	else if (argument->flags[5])
		return (ft_print_number(argument, "+"));
	else if (argument->flags[6])
		return (ft_print_number(argument, " "));
	return (ft_print_number(argument, ""));
}

// int ft_do_the_dope_walk(int len, int precision, int padding, PF *argument)
// {
// 	return(0);
// }

int					ft_print_number(PF *argument, char *pre)
{
	ssize_t		len;
	ssize_t		precision;
	ssize_t		padding;

	argument->arg = test_string(argument);
	len = (ssize_t)ft_strlen(argument->arg);
	precision = 0;
	padding = 0;
	if (argument->flags[0] > len)
		precision = argument->flags[0] - len;
	len += (ssize_t)ft_strlen(pre) + precision;
	if (argument->flags[1] > len)
		padding = argument->flags[1] - len;
	if (argument->flags[4] == 0 && (argument->flags[3] == 0
		|| argument->flags[0] != -1))
		ft_nputchar(' ', padding);
	ft_buff(pre);
	if (argument->flags[3] == 1 && argument->flags[4] == 0
		&& argument->flags[0] == -1)
		ft_nputchar('0', padding);
	ft_nputchar('0', precision);
	ft_buff(argument->arg);
	if (argument->flags[4] == 1)
		ft_nputchar(' ', padding);
	return (0);
}
