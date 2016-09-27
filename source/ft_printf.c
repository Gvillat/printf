/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 17:35:42 by gvillat           #+#    #+#             */
/*   Updated: 2016/09/27 17:35:43 by gvillat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_get_flags(PF *argu, va_list ap)
{
	argu->index = 0;
	while (argu->format[argu->index] == '#' || argu->format[argu->index] == '0'
		|| argu->format[argu->index] == '-' || argu->format[argu->index] == '+'
		|| argu->format[argu->index] == ' ' || argu->format[argu->index] == 'h'
		|| argu->format[argu->index] == 'l' || argu->format[argu->index] == 'j'
		|| argu->format[argu->index] == 'z' || argu->format[argu->index] == '.'
		|| argu->format[argu->index] == '*' ||
		ft_isdigit(argu->format[argu->index]))
	{
		ft_check_flags(argu);
		ft_check_width(argu);
		ft_check_precision(argu);
		ft_check_length(argu);
	}
	ft_check_spec(argu);
	if (argu->index == ft_strlen(argu->format))
		return (-1);
	return (argu->index);
}

int		ft_check_format(char *str, PF *argument, va_list ap)
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
				return (-1);
			spe->spe[argument->spec](argument, ap);
			i += argument->index;
		}
		else if (str[i] != '%' && str[i] != '\0')
		{
			g_buff[g_i] = str[i];
			g_i++;
		}
	}
	return (0);
}

int		ft_printf(const char *format, ...)
{
	va_list ap;
	PF		argument;

	argument.ret = 0;
	if (!format)
		return (0);
	va_start(ap, format);
	ft_init_buff();
	ft_check_format((char*)format, &argument, ap);
	if (g_i)
		ft_display(&argument);
	ft_putchar('\n');
	va_end(ap);
	return (argument.ret);
}
