/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 17:35:05 by gvillat           #+#    #+#             */
/*   Updated: 2016/09/27 17:35:06 by gvillat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int					ft_arg_nospe(PF *argument, va_list ap)
{
	char c[2];

	c[0] = argument->spec;
	c[1] = '\0';
	ft_print_character(argument, c);
	return ((int)ap);
}

static int			wchar_handler(va_list ap, PF *argument)
{
	wchar_t			c;
	char			*s;

	c = (wchar_t)va_arg(ap, wchar_t);
	if (c == 0)
	{
		ft_putchar(0);
		return (0);
	}
	else if (c < 0)
		return (-1);
	if (!(s = ft_strnew(4)))
		return (-1);
	ft_wchartostr(s, c);
	argument->flags[0] = -1;
	ft_print_str(argument, s);
	return (0);
}

int					character_handler(PF *argument, va_list ap)
{
	char	c[2];

	if (argument->spec == 'C' || argument->flags[10] == 1)
		return (wchar_handler(ap, argument));
	c[0] = (char)va_arg(ap, int);
	c[1] = '\0';
	ft_print_character(argument, c);
	return (0);
}

int					ft_print_character(PF *argument, char *c)
{
	ssize_t		len;
	ssize_t		padding;

	len = 1;
	padding = 0;
	if (argument->flags[1] > len)
		padding = argument->flags[1] - len;
	if (argument->flags[4] == 0 && argument->flags[3] == 0)
		ft_nputchar(' ', padding);
	if (argument->flags[3] == 1 && argument->flags[4] == 0)
		ft_nputchar('0', padding);
	if (!c || c[0] == 0)
		g_i++;
	else
		ft_buff(c);
	if (argument->flags[4] == 1)
		ft_nputchar(' ', padding);
	return (0);
}
