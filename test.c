#include "ft_printf.h"
#include <locale.h>

int main(int argc, char **argv)
{
	setlocale(LC_ALL, "");
	ft_putwchar_fd(0xFDF0,1);
	ft_putwchar_fd('\n',1);
	return 0;
}
