#include "ft_printf.h"

void	flag_s(va_list *args, int bn)
{
	ft_putstr(va_arg(args, char *));
	if_bn(bn);
}

void	flag_S(va_list *args, int bn)
{
	
	if_bn(bn);
}

void	flag_p(va_list *args, int bn)
{
	
	if_bn(bn);
}

void	flag_d(va_list *args, int bn)
{
	ft_putnbr(va_arg(args, int));
	if_bn(bn);
}

void	flag_D(va_list *args, int bn)
{
	
	if_bn(bn);
}
