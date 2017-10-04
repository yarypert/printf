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
	printf("UNIX_1_@moulitest: %#x\n", 0);
	printf("UNIX_2_@moulitest: %#.x\n", 0);
	printf("UNIX_3_@moulitest: %#.0x\n", 0);
	printf("UNIX_4_@moulitest: %x\n", 0);
	printf("UNIX_5_@moulitest: %.x\n", 0);
	printf("UNIX_6_@moulitest: %.0x\n", 0);
	ft_printf("FTPF_1_@moulitest: %#x\n", 0);
	ft_printf("FTPF_2_@moulitest: %#.x\n", 0);
	ft_printf("FTPF_3_@moulitest: %#.0x\n", 0);
	ft_printf("FTPF_4_@moulitest: %x\n", 0);
	ft_printf("FTPF_5_@moulitest: %.x\n", 0);
	ft_printf("FTPF_6_@moulitest: %.0x\n", 0);
return (0);
}
