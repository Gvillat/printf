/* ***********************************************************9*************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 17:35:28 by gvillat           #+#    #+#             */
/*   Updated: 2016/09/27 17:35:30 by gvillat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_display(PF *argument)
{
	argument->ret += write(1, &g_buff, g_i);
	ft_init_buff();
}

void ft_buf(char c, PF *argument)
{
	g_buff[g_i] = c;
	g_i++;
	if (g_i == 8192)
		ft_display(argument);
}

void	*ft_buff(char *str, PF *argument)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{		
		ft_buf(str[i++], argument);
	}
	return (NULL);
}
