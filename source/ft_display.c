/* ************************************************************************** */
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

int		ft_display(PF *argument)
{
	argument->ret = write(1, &g_buff, g_i);
	return (argument->ret);
}

void	*ft_buff(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		g_buff[g_i] = str[i];
		i++;
		g_i++;
	}
	return (NULL);
}
