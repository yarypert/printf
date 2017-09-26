#include <locale.h>
#include <stdio.h>
#include <inttypes.h>
#include "./Libft/libft.h"



#include <string.h>
#include <stdint.h>
#include <time.h>

int main(void)
{
	setlocale(LC_ALL, "");
	printf("%#08x\n", 255);
	ft_printf("%#08x\n", 255);
	return (0);
}
