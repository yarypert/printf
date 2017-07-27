#include "includes/ft_printf.h"
#include <locale.h>

int main(int argc, char **argv)
{
	setlocale(LC_ALL, "");
	ft_putwchar_fd(0xFDF0,1);
	ft_putwchar_fd('\n',1);
	ft_putwchar_fd(0x1f4a9,1);
	ft_putwchar_fd('\n',1);

	printf("%x\n", 150);
	printf("%X\n", 150);
	return 0;
}
