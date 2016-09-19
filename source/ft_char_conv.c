#include "../includes/ft_printf.h"

void 	*ft_arg_c(PF *argument , va_list ap)
{
	char c[2];

	if (argument->flags[10] == 1 || argument->spec == 'C')
		c[0] = (wint_t)ap;
	else
		c[0] = (int)ap;
	c[1] = '\0';
	return(ft_apply_flags(c, argument, ap));
}

void *ft_arg_nospe(PF *argument, va_list ap)
{
	char c[2];

	c[0] = argument->spec;
	c[1] = '\0';
	return(ft_apply_flags(c, argument, ap));
}

void *ft_arg_prc(PF *argument, va_list ap)
{
	if (argument->spec == '%')
		return(ft_apply_flags("%\0", argument, ap));
	return(NULL);
}

// str
// char
// signed
// unsigned
// ptr