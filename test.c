#include <locale.h>
#include <stdio.h>
#include <inttypes.h>
#include "./Libft/libft.h"
#include "limits.h"
#include <string.h>
#include <stdint.h>
#include <time.h>

int main(void)
{
//	setlocale(LC_ALL, "");
	printf("%O\n", LONG_MAX);
	ft_printf("%O\n", LONG_MAX);
	return (0);
}
