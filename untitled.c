#include "includes/ft_printf.h"

int main(int ac, char **av)
{
	wchar_t *c;
	char a, b, *s;
	int d, e;
	unsigned int f;

	f = d;
	d = -12;
	e = 0;
	a = 's';
	b = 75;
	s = "argument";
	c = L"ĈЄĈĪ Є$Ŧ ЦИ ŦЄXŦЄ ÐЄ ŦØЦ PØЦR ПØИ PRĪИŦŦ. ʖЄ $ЦĪ$ 42, ЄŦ ʖЄ $ЦĪ$ PRĪИŦŦ.";
	ft_printf(av[1], a, b, e, d, &f, s);
	printf("\n");
	printf(av[1], a, b, e, d, &f, s);
	return(0);
}