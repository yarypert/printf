#include "ft_printf.h"

void	flag_X(va_list *args, int bn)
{
	if_bn(bn);
	
}

void	flag_c(va_list *args, int bn)
{
	ft_putchar(va_arg(args, int));
	if_bn(bn);
}

void	flag_C(va_list *args, int bn)
{
	
	if_bn(bn);
}

void	if_bn(int bn)
{
	if (bn == 1)
		ft_putchar('\n');
}
