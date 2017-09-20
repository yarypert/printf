#include <locale.h>
#include <stdio.h>
#include <inttypes.h>
#include "./Libft/libft.h"

/*
   setlocale(LC_ALL, "");
   ft_putwchar_fd(0xFDF0,1);
   ft_putwchar_fd('\n',1);
   ft_putwchar_fd(0x1f4a9,1);
   ft_putwchar_fd('\n',1);
   */

#include <string.h>
#include <stdint.h>
#include <time.h>

int main(void)
{
	printf("%20.15d\n", 54321);
	ft_printf("%20.15d\n", 54321);
	return (0);
}
