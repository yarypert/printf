#include "ft_printf.h"
#include <locale.h>

int main(int argc, char **argv)
{
	//setlocale(LC_ALL, "");
	//ft_putwchar_fd(0xFDF0,1);
	//ft_putwchar_fd('\n',1);
	
	printf("%d\n", 2147483647);
	printf("%hd\n", (short)32767);
	printf("%hhd\n", (signed char)127);
	printf("%ld\n", (long)9223372036854775807);
	printf("%lld\n", (long long)9223372036854775807);

	return 0;
}
