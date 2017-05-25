#include "ft_printf.h"

int		analyse(va_list *args, char *format)
{
	parse_format(format, args);
}
