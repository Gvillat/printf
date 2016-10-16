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

int		ft_display(void)
{
	int ret;
	ret = write(1, &g_buff, g_i);
	ft_init_buff();
	return (ret);
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
	if (g_i == 4096)
		ft_display();
	return (NULL);
}
