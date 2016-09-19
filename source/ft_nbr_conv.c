#include "../includes/ft_printf.h"

void *ft_arg_d(PF *argument, va_list ap)
{
	char *res;
	int nbr;

	res = NULL;
	nbr = ft_signe((int)ap, argument);
	if (argument->flags[12] == 1 && argument->spec != 'D')
		res = ft_itoa_base((intmax_t)((ssize_t)nbr), 10);
	else if (argument->flags[11] == 1 && argument->spec != 'D')
		res = ft_itoa_base((intmax_t)((intmax_t)nbr), 10);
	else if (argument->flags[10] == 1 || argument->spec == 'D')
		res = ft_itoa_base((intmax_t)((long)nbr), 10);
	else if (argument->flags[9] == 1 && argument->spec != 'D')
		res = ft_itoa_base((intmax_t)((long long)nbr), 10);
	else if (argument->flags[8] == 1 && argument->spec != 'D')
		res = ft_itoa_base((intmax_t)((short)nbr), 10);
	else if (argument->flags[7] == 1 && argument->spec != 'D')
		res = ft_itoa_base((intmax_t)((char)nbr), 10);
	else if (argument->spec == 'd' || argument->spec == 'i')
		res = ft_itoa_base((intmax_t)((int)nbr), 10);
	return(ft_apply_flags(res, argument, ap));
}

void 	*ft_arg_p(PF *argument, va_list ap)
{
	void *p;
	// char *s;

	// s = "0x";
	p = ft_itoa_base((uintmax_t)(void*)ap, 16);
	p = (char*)ft_strlower(p);
	// p = ft_strjoin(s, p);
	return(ft_apply_flags(p, argument, ap));
}



void *ft_arg_x(PF *argument, va_list ap)
{
	char *res;

	res = NULL;
	if (argument->flags[12] == 1 && argument->spec != 'X')
		res = ft_itoa_base((uintmax_t)((ssize_t)ap),16);
	else if (argument->flags[11] == 1 && argument->spec != 'X')
		res = ft_itoa_base((uintmax_t)((uintmax_t)ap),16);
	else if (argument->flags[10] == 1 || argument->spec == 'X')
		res = ft_itoa_base((uintmax_t)((unsigned long int)ap),16);
	else if (argument->flags[9] == 1 && argument->spec != 'X')
		res = ft_itoa_base((uintmax_t)((unsigned long long int)ap),16);
	else if (argument->flags[8] == 1 && argument->spec != 'X')
		res = ft_itoa_base((uintmax_t)((unsigned short int)ap), 16);
	else if (argument->flags[7] == 1 && argument->spec != 'X')
		res = ft_itoa_base((uintmax_t)((unsigned char)ap), 16);
	else if (argument->spec == 'x')
		res = ft_itoa_base((uintmax_t)((unsigned int)ap), 16);
	return(ft_apply_flags(ft_strlower(res), argument, ap));
}

void 	*ft_arg_u(PF *argument , va_list ap)
{
	char *res;

	res = NULL;
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
	return(ft_apply_flags(res, argument, ap));

}

void 	*ft_arg_o(PF *argument , va_list ap)
{
	char *res;

	res = NULL;
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
	return(ft_apply_flags(res, argument, ap));
}