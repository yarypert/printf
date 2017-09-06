#include <locale.h>
#include <stdio.h>

int main(int argc, char **argv)
{
/*
	setlocale(LC_ALL, "");
	ft_putwchar_fd(0xFDF0,1);
	ft_putwchar_fd('\n',1);
	ft_putwchar_fd(0x1f4a9,1);
	ft_putwchar_fd('\n',1);
*/
	printf("%10.d\n", 164164);
	printf("%10.8d\n", 164164);
	printf("%.4s\n", "coucou");
	printf("%8.4s\n", "coucou");
	return 0;
}
