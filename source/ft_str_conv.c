/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:27:43 by guvillat          #+#    #+#             */
/*   Updated: 2019/01/23 15:27:43 by guvillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			ft_display(PF *argument)
{
	argument->ret += write(1, &g_buff, g_i);
	ft_init_buff();
}

static int		wstring_handler(PF *argument, va_list ap)
{
	ssize_t len;

	argument->warg = va_arg(ap, wchar_t *);
	argument->spec = 'S';
	if (!argument->warg)
		argument->warg = L"(null)";
	len = ft_wbytelen(argument->warg);
	if (argument->flags[0] > -1 && argument->flags[0] < len)
		argument->arg = ft_wstrsub(argument->warg, 0, argument->flags[0]);
	else
		argument->arg = ft_transform_wchar_in_char(argument->warg);
	return (ft_print_str(argument));
}

int				string_handler(PF *argument, va_list ap)
{
	ssize_t len;
	char	*tmp;

	if (argument->spec == 'S' || argument->flags[10] == 1)
		return (wstring_handler(argument, ap));
	argument->arg = va_arg(ap, char *);
	if (!argument->arg)
		argument->arg = "(null)";
	len = ft_strlen(argument->arg);
	if (argument->flags[0] > -1 && argument->flags[0] < len)
	{
		tmp = ft_strsub(argument->arg, 0, argument->flags[0]);
		argument->arg = tmp;
		free(tmp);
	}
	return (ft_print_str(argument));
}

int				ft_print_str(PF *argument)
{
	ssize_t		len;
	ssize_t		padding;
	int			i;

	i = -1;
	if (!argument->arg)
		return (-1);
	len = (ssize_t)ft_strlen(argument->arg);
	padding = 0;
	if (argument->flags[0] > -1 && argument->flags[0] < len)
		len = argument->flags[0];
	if (argument->flags[1] > len)
		padding = argument->flags[1] - len;
	if (argument->flags[4] == 0 && argument->flags[3] == 0)
		ft_nputchar(' ', padding, argument);
	if (argument->flags[3] == 1 && argument->flags[4] == 0)
		ft_nputchar('0', padding, argument);
	ft_buff(argument->arg, argument);
	if (argument->flags[4] == 1)
		ft_nputchar(' ', padding, argument);
	if ((argument->spec == 'C' || argument->spec == 'S'))
		free(argument->arg);
	return (0);
}
