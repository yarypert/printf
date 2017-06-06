#include "ft_printf.h"

int		is_close(char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' ||
			c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'U' ||
			c == 'x' || c == 'X' || c == 'c' || c == 'C' || c == '%')
		return(1);
	return(0);
}

int count_flags(char *str)
{
	int		count;
	int		i = 0;
	int		open_flag;
	int		open_str;
	i = 0;
	count = 0;
	open_flag = 0;
	open_str = 0;
	if(str[0] == '%')
		open_flag = 1;
	else
		open_str = 1;
	while (str[i])
	{
		if(open_str == 0 && str[i] != '%')
		{
			open_str = 1;
			i++;
		}
		if(open_str == 1 && (str[i + 1] == '%' || str[i + 1] == '\0'))
		{
			open_str = 0;
			count++;
		}

		if(str[i] == '%')
		{
			open_flag = 1;
			open_str = 0;
			i++;
		}
		if (is_close(str[i]) && open_flag == 1)
		{
			open_flag = 0;
			count++;
		}
			i++;
	}
	return(count);
}


char	**flagsplit(char *format)
{
	char **tabformat;
	int count;
	count = count_flags(format);
	ft_putnbr(count);
	return(tabformat);
}

int main(int argc, char **argv)
{
	char *format;
	char **tabformat;
	format = (char *)argv[1];
	tabformat = flagsplit(format);
}
