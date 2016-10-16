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
	ssize_t		len;
	ssize_t		tmp;

	argument->warg = va_arg(ap, wchar_t *);
	if (!argument->warg)
		argument->warg = L"(null)";
	tmp = argument->flags[1];
	len = ft_wstrlen(argument->warg) * 4;
	if (!(argument->arg = ft_strnew((size_t)len)))
		return (-1);
	ft_wstrtostr(argument->arg, argument->warg, (tmp > -1 && len > tmp) ? tmp : len);
	return (ft_print_str(argument));
}

int				string_handler(PF *argument, va_list ap)
{
	if (argument->spec == 'S' || argument->flags[10] == 1)
		return (wstring_handler(argument, ap));
	argument->arg = va_arg(ap, char *);
	if (!argument->arg)
		argument->arg = ft_strdup("(null)");
	return (ft_print_str(argument));
} 

int				ft_print_str(PF *argument)
{
	ssize_t		len;
	ssize_t		padding;
	char		*tmp;

	if (!argument->arg)
		return (-1);
	len = (ssize_t)ft_strlen(argument->arg);
	padding = 0;
	if (argument->flags[0] > -1 && argument->flags[0] < len)
		len = argument->flags[0];
	if (!(tmp = (char*)malloc(sizeof(len))))
		return (-1);
	if (argument->flags[1] > len)
		padding = argument->flags[1] - len;
	if (argument->flags[4] == 0 && argument->flags[3] == 0)
		ft_nputchar(' ', padding);
	if (argument->flags[3] == 1 && argument->flags[4] == 0)
		ft_nputchar('0', padding);
	tmp = ft_strsub(argument->arg, 0, len);
	ft_buff(tmp);
	free(tmp);
	if (argument->flags[4] == 1)
		ft_nputchar(' ', padding);
	return (0);
}
