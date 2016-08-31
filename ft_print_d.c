#include "includes/ft_printf.h"

void *ft_arg_d(PF *argument, va_list ap)
{
	char *res;

	if (argument->flags[12] == 1 && argument->spec != 'D')
		res = ft_itoa_base((uintmax_t)((ssize_t)ap), 10);
	else if (argument->flags[11] == 1 && argument->spec != 'D')
		res = ft_itoa_base((uintmax_t)((intmax_t)ap), 10);
	else if (argument->flags[10] == 1 || argument->spec == 'D')
		res = ft_itoa_base((uintmax_t)((long)ap), 10);
	else if (argument->flags[9] == 1 && argument->spec != 'D')
		res = ft_itoa_base((uintmax_t)((long long)ap), 10);
	else if (argument->flags[8] == 1 && argument->spec != 'D')
		res = ft_itoa_base((uintmax_t)((short)ap), 10);
	else if (argument->flags[7] == 1 && argument->spec != 'D')
		res = ft_itoa_base((uintmax_t)((char)ap), 10);
	else if (argument->spec == 'd' || argument->spec == 'i')
		res = ft_itoa_base((uintmax_t)((int)ap), 10);
	return(ft_buff(argument, res));
}

void *ft_arg_s(PF *argument, va_list ap)
{
	char *str;
	wchar_t *res;

	if (argument->flags[10] == 1)
	{
		res = (wchar_t*)ap;
		return(ft_buff(argument, (char*)res));
	}
	else
	{
		str = (char*)ap;
		return(ft_buff(argument, str));
	}
}

void 	*ft_arg_c(PF *argument , va_list ap)
{
	char c[2];

	if (argument->flags[10] == 1 || argument->spec == 'C')
		c[0] = (wint_t)ap;
	else
		c[0] = (int)ap;
	c[1] = '\0';
	return(ft_buff(argument, c));
}

void 	*ft_arg_p(PF *argument, va_list ap)
{
	void *p;

	ft_buff(argument, "0x");
	p = ft_itoa_base((uintmax_t)(void*)ap, 16);
	p = ft_strlower(p);
	return(ft_buff(argument, (char*)p));
}

void *ft_arg_nospe(PF *argument, va_list ap)
{
	char c[2];

	c[0] = argument->spec;
	c[1] = '\0';
	return(ft_buff(argument, c));
}

void * ft_strlower(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] = ft_tolower(s[i]);
		i++; 
	}
	return(s);
}

void *ft_arg_prc(PF *argument, va_list ap)
{
	if (argument->spec == '%')
		return(ft_buff(argument, "%\0"));
	return(NULL);
}

void 	*ft_arg_u(PF *argument , va_list ap)
{
	char *res;

	if (argument->flags[12] == 1 && argument->spec != 'U')
		res = ft_itoa_base((uintmax_t)((ssize_t)ap),10);
	else if (argument->flags[11] == 1 && argument->spec != 'U')
		res = ft_itoa_base((uintmax_t)((uintmax_t)ap),10);
	else if (argument->flags[10] == 1 || argument->spec == 'U')
		res = ft_itoa_base((uintmax_t)((unsigned long int)ap),10);
	else if (argument->flags[9] == 1 && argument->spec != 'U')
		res = ft_itoa_base((uintmax_t)((unsigned long long int)ap),10);
	else if (argument->flags[8] == 1 && argument->spec != 'U')
		res = ft_itoa_base((uintmax_t)((unsigned short int)ap), 10);
	else if (argument->flags[7] == 1 && argument->spec != 'U')
		res = ft_itoa_base((uintmax_t)((unsigned char)ap), 10);
	else if (argument->spec == 'u')
		res = ft_itoa_base((uintmax_t)((unsigned int)ap), 10);
	return(ft_buff(argument, res));
}

void 	*ft_arg_o(PF *argument , va_list ap)
{
	char *res;

	if (argument->flags[12] == 1 && argument->spec != 'O')
		res = ft_itoa_base((uintmax_t)((ssize_t)ap), 8);
	else if (argument->flags[11] == 1 && argument->spec != 'O')
		res = ft_itoa_base((uintmax_t)((uintmax_t)ap), 8);
	else if (argument->flags[10] == 1 || argument->spec == 'O')
		res = ft_itoa_base((uintmax_t)((unsigned long int)ap), 8);
	else if (argument->flags[9] == 1 && argument->spec != 'O')
		res = ft_itoa_base((uintmax_t)((unsigned long long int)ap), 8);
	else if (argument->flags[8] == 1 && argument->spec != 'O')
		res = ft_itoa_base((uintmax_t)((unsigned short int)ap), 8);
	else if (argument->flags[7] == 1 && argument->spec != 'O')
		res = ft_itoa_base((uintmax_t)((unsigned char)ap), 8);
	else if (argument->spec == 'o')
		res = ft_itoa_base((uintmax_t)((unsigned int)ap), 8);
	return(ft_buff(argument, res));
}

// void 	*ft_arg_prc(void *, va_list)
// {

// }