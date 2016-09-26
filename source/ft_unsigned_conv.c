#include "../includes/ft_printf.h"

static uintmax_t		unsigned_cast(PF *argument, va_list ap)
{
	uintmax_t			n;

	n = va_arg(ap, uintmax_t);
	if (argument->flags[7] == 1)
		n = (unsigned char)(n);
	else if (argument->flags[8] == 1)
		n = (unsigned short)(n);
	else if (argument->flags[10] == 1)
		n = (unsigned long)(n);
	else if (argument->flags[9] == 1)
		n = (unsigned long long)(n);
	else if (argument->flags[11] == 1)
		n = (uintmax_t)(n);
	else if (argument->flags[12] == 1)
		n = (size_t)(n);
	else
		n = (unsigned int)(n);
	return (n);
}

static int				unsigned_helper(PF *argument, char *s)
{
	ssize_t				len;
	int					nullstr;

	if (!s)
		return (-1);
	len = (ssize_t)ft_strlen(s);
	nullstr = (len == 1 && s[0] == '0') ? 0 : 1;
	if (argument->flags[2] == 1)
	{
		if (argument->spec == 'o' || argument->spec == 'O')
		{
			if (argument->flags[0] <= len && s[0] != '0')
				argument->flags[0] = len + 1;
		}
		else if (argument->spec == 'x' && nullstr != 0)
			return (ft_print_number(argument, "0x", s));
		else if (argument->spec == 'X' && nullstr != 0)
			return (ft_print_number(argument, "0X", s));
	}
	return (ft_print_number(argument, "", s));
}

int						unsigned_handler(PF *argument, va_list ap)
{
	uintmax_t			n;

	if (argument->flags[3] == 1)
		argument->zeropadding = 1;
	if (argument->zeropadding == 0 && argument->flags[4] == 1)
		argument->rightpadding = 0;
	if (argument->spec == 'x' || argument->spec == 'X' || argument->spec == 'u' || argument->spec == 'o')
		n = unsigned_cast(argument, ap);
	else
		n = (unsigned long int)va_arg(ap, uintmax_t);
	if (argument->spec == 'o' || argument->spec == 'O')
		return (unsigned_helper(argument, ft_itoa_base(n, 8)));
	else if (argument->spec == 'u' || argument->spec == 'U')
		return (unsigned_helper(argument, ft_itoa_base(n , 10)));
	else if (argument->spec == 'x')
		return (unsigned_helper(argument, ft_strlower(ft_itoa_base(n , 16))));
	else
		return (unsigned_helper(argument, ft_itoa_base(n, 16)));
}