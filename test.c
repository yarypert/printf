#include <locale.h>
#include <stdio.h>
#include <inttypes.h>
#include "./Libft/libft.h"



#include <string.h>
#include <stdint.h>
#include <time.h>


void test(int64_t i)
{
	ft_putstr(ft_ltoa(i));
}


int main(void)
{
	setlocale(LC_ALL, "");
	test(-9223372036854775808);
	return (0);
}
