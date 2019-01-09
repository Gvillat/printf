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
		ft_check_width(argu, ap);
		ft_check_precision(argu, ap);
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
			ft_buf(str[i], argument);
	}
	return (0);
}

char	*ft_strcat(char *dest, const char *src)
{
	int i;
	int j;

	i = ft_strlen(dest);
	j = 0;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char *str;

	if (!(char*)s1 || !(char*)s2)
		return (NULL);
	if (!(str = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	ft_strcat(str, s1);
	ft_strcat(str, s2);
	return (str);
}


char	*ft_strcpy(char *dst, const char *src)
{
	char *d;

	if (!src)
		return (dst);
	d = dst;
	while (*src)
		*d++ = *src++;
	*d = '\0';
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	char	*dst;

	if (!(dst = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1)))
		return (NULL);
	return (ft_strcpy(dst, s1));
}

void	ft_bzero(void *s, size_t n)
{
	if (!n)
		return ;
	*((char *)s) = 0;
	while (--n > 0)
		((char *)s)[n] = '\0';
}


static int		numlen(long n)
{
	int		i;

	i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static	void	converter(char *buffer, long n, int i)
{
	if (n > 0)
	{
		converter(buffer, n / 10, --i);
		buffer[i] = n % 10 + '0';
	}
}

char			*ft_itoa(int n)
{
	int		flag;
	char	buffer[12];

	if (n == 0)
		return (ft_strdup("0"));
	flag = 0;
	ft_bzero(buffer, 12);
	if (n < 0)
		buffer[flag++] = '-';
	converter(buffer + flag, flag == 0 ? (long)n : -(long)n, numlen(n));
	return (ft_strdup(buffer));
}

int		ft_round(float nb)
{
	return (nb >= 0 ? (int)(nb + 0.5) : (int)(nb - 0.5));
}


char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*str;

	str = s1;
	while (*str)
		str++;
	while (*s2 && n)
	{
		*str++ = *s2++;
		n--;
	}
	*str = '\0';
	return (s1);
}

char *ft_ftoa(long double nbr, PF *argument)
{
	int precision;
	uintmax_t curr;
	uintmax_t res;
	char *tmp;
	uintmax_t nb;

	precision = argument->flags[0];
	res = 0;
	curr = 0;
	nb = 0;
	tmp = ft_strnew(64);
	argument->arg = ft_strcat(ft_itoa_base((uintmax_t)nbr, 10), ".");
	nbr = (long double)nbr - (int)nbr;
	if (precision == -1)
		precision = 6;
	while (precision)
	{
		nbr *= 10;
		curr = (uintmax_t)nbr;
		curr %= 10;
		nb = nb * 10 + curr;
		precision--;
		tmp = ft_strncat(tmp, ft_itoa_base(curr, 10), 1);
	}
	if (argument->flags[0] == -1 && curr == 9)
	{
		nb++;
		argument->arg = ft_strcat(argument->arg, ft_itoa_base(nb, 10));
	}
	else
		argument->arg = ft_strcat(argument->arg, tmp);
	free(tmp);
	return (argument->arg);
}

int					float_handler(PF *argument, va_list ap)
{
	long double	n;

	n = (long double)va_arg(ap, double);
	if (n > 0)
		argument->arg = ft_ftoa(n, argument);
	else if (n < 0)
	{
		argument->arg = ft_ftoa(-n, argument);
		return (ft_print_number(argument, "-"));
	}
	if (argument->flags[5])
		return (ft_print_number(argument, "+"));
	if (argument->flags[6])
		return (ft_print_number(argument, " "));
	return (ft_print_number(argument, ""));
}

/*	Quand il est utilisé avec le format e, E, f, F, a ou A, l’indicateur # impose à la valeur de sortie de contenir une virgule décimale.*/


int		ft_printf(const char *format, ...)
{
	va_list ap;
	PF		argument;

	if (!format)
		return (-1);
	g_i = 0;
	argument.ret = 0;
	va_start(ap, format);
	ft_init_argument(&argument);
	ft_init_buff();
	ft_check_format((char*)format, &argument, ap);
	if (g_i)
		ft_display(&argument);
	va_end(ap);
	return (argument.ret);
}
