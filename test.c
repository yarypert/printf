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
	printf("UNIX_1_@moulitest: %#.x %#.0x\n", 0, 0);
	printf("UNIX_2_@moulitest: %.x %.0x\n", 0, 0);
	printf("UNIX_3_@moulitest: %5.x %5.0x\n", 0, 0);
	ft_printf("FTPF_1_@moulitest: %#.x %#.0x\n", 0, 0);
	ft_printf("FTPF_2_@moulitest: %.x %.0x\n", 0, 0);
	ft_printf("FTPF_3_@moulitest: %5.x %5.0x\n", 0, 0);
return (0);
}
