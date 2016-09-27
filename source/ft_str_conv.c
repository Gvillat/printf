/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 17:35:56 by gvillat           #+#    #+#             */
/*   Updated: 2016/09/27 17:35:59 by gvillat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		wstring_handler(PF *argument, va_list ap)
{
	wchar_t		*ws;
	char		*s;
	ssize_t		len;
	ssize_t		tmp;

	ws = va_arg(ap, wchar_t *);
	if (!ws)
		ws = L"(null)";
	tmp = argument->flags[1];
	len = ft_wstrlen(ws) * 4;
	if (!(s = ft_strnew((size_t)len)))
		return (-1);
	ft_wstrtostr(s, ws, (tmp > -1 && len > tmp) ? tmp : len);
	return (ft_print_wstr(argument, s));
}

int				string_handler(PF *argument, va_list ap)
{
	char		*tmp;
	char		*s;

	if (argument->spec == 'S' || argument->flags[10] == 1)
		return (wstring_handler(argument, ap));
	tmp = va_arg(ap, char *);
	if (!tmp)
		s = ft_strdup("(null)");
	else
		s = ft_strdup(tmp);
	return (ft_print_str(argument, s));
}

int				ft_print_str(PF *argument, char *s)
{
	ssize_t		len;
	ssize_t		padding;

	if (!s)
		return (-1);
	len = (ssize_t)ft_strlen(s);
	padding = 0;
	if (argument->flags[0] > 0 && argument->flags[0] < len)
		len = argument->flags[0];
	if (argument->flags[1] > len)
		padding = argument->flags[1] - len;
	if (argument->flags[4] == 0 && argument->flags[3] == 0)
		ft_nputchar(argument, ' ', padding);
	if (argument->flags[3] == 1)
		ft_nputchar(argument, '0', padding);
	ft_buff(argument, s);
	if (argument->flags[4] == 1)
		ft_nputchar(argument, ' ', padding);
	free(s);
	return (0);
}

int				ft_print_wstr(PF *argument, char *s)
{
	ssize_t		len;
	ssize_t		padding;

	if (!s)
		return (-1);
	len = (ssize_t)ft_strlen(s);
	padding = 0;
	if (argument->flags[0] > 0 && argument->flags[0] < len)
		len = argument->flags[0];
	if (argument->flags[1] > len)
		padding = argument->flags[1] - len;
	if (argument->flags[4] == 0 && argument->flags[3] == 0)
		ft_nputchar(argument, ' ', padding);
	if (argument->flags[3] == 1)
		ft_nputchar(argument, '0', padding);
	ft_buff(argument, s);
	if (argument->flags[4] == 1)
		ft_nputchar(argument, ' ', padding);
	free(s);
	return (0);
}
