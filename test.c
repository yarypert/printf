#include "ft_printf.h"
#include <locale.h>

int main(int argc, char **argv)
{/*
	setlocale(LC_ALL, "");
	ft_putwchar_fd(0xFDF0,1);
	ft_putwchar_fd('\n',1);
	ft_putwchar_fd(0x1f4a9,1);
	ft_putwchar_fd('\n',1);
*/
	printf("%o\n", 55);
	ft_putstr(ft_itoa_base(55, 8));
	return 0;
}
