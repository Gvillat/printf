#include "includes/ft_printf.h"

int main(int ac, char **av)
{
	wchar_t *c;
	char a, b, *s;
	int d, e;
	unsigned long long f;

	f = 9223372036854775807;
	d = 0;
	e = 1;
	a = 'a';
	b = 75;
	s = "argument";
	c = L"ĈЄĈĪ Є$Ŧ ЦИ ŦЄXŦЄ ÐЄ ŦØЦ PØЦR ПØИ PRĪИŦŦ. ʖЄ $ЦĪ$ 42, ЄŦ ʖЄ $ЦĪ$ PRĪИŦŦ.";
	e = ft_printf("%4.15S", L"我是一只猫。");
	printf("%d \n", e);
	e = ft_printf("%15.4S", L"我是一只猫。");
	printf("%d \n", e);
	e =	ft_printf("%.4S", L"我是一只猫。");
	printf("%d \n", e);
	e =	ft_printf("%30S", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	printf("%d \n", e);
	return(0);
}
