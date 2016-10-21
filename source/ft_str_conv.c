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

int			ft_wcharlen(wchar_t wchar)
{
	if (wchar <= 0x7f)
		return (1);
	else if (wchar <= 0x7ff)
		return (2);
	else if (wchar <= 0xffff)
		return (3);
	else
		return (4);
}

static size_t		ft_wbytelen(wchar_t *ws)
{
	size_t	len;
	size_t	bytelen;

	len = ft_wstrlen(ws);
	bytelen = 0;
	while (len > 0)
	{
		bytelen += ft_wcharlen(*ws);
		ws++;
		len--;
	}
	return (bytelen);
}

static int		ft_putwchar_in_char(wchar_t wchar, char *fresh, int i)
{
	int		size;

	size = ft_wcharlen(wchar);
	if (size == 1)
		fresh[i++] = wchar;
	else if (size == 2)
	{
		fresh[i++] = (wchar >> 6) + 0xC0;
		fresh[i++] = (wchar & 0x3F) + 0x80;
	}
	else if (size == 3)
	{
		fresh[i++] = (wchar >> 12) + 0xE0;
		fresh[i++] = ((wchar >> 6) & 0x3F) + 0x80;
		fresh[i++] = (wchar & 0x3F) + 0x80;
	}
	else
	{
		fresh[i++] = (wchar >> 18) + 0xF0;
		fresh[i++] = ((wchar >> 12) & 0x3F) + 0x80;
		fresh[i++] = ((wchar >> 6) & 0x3F) + 0x80;
		fresh[i++] = (wchar & 0x3F) + 0x80;
	}
	return (i);
}

char	*ft_transform_wchar_in_char(wchar_t *ws)
{
	char	*fresh;
	int		i;
	int		k;
	int		len;

	if (!ws)
		return (0);
	i = 0;
	k = 0;
	len = ft_wbytelen(ws);
	fresh = (char*)malloc(len + 1  * (sizeof(char)));
	fresh[len] = '\0';
	while (ws[k])
	{
		i = ft_putwchar_in_char(ws[k], fresh, i);
		k++;
	}
	return (fresh);
}

static int		wstring_handler(PF *argument, va_list ap)
{
	ssize_t len;

	argument->warg = va_arg(ap, wchar_t *);
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

	if (argument->spec == 'S' || argument->flags[10] == 1)
		return (wstring_handler(argument, ap));
	argument->arg = va_arg(ap, char *);
	if (!argument->arg)
		argument->arg = ft_strdup("(null)");
	len = ft_strlen(argument->arg);
	if (argument->flags[0] > -1 && argument->flags[0] < len)
		argument->arg = ft_strsub(argument->arg, 0, argument->flags[0]);
	return (ft_print_str(argument));
} 


int				ft_print_str(PF *argument)
{
	ssize_t		len;
	ssize_t		padding;
	int i;

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
	return (0);
}