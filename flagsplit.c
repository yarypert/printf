#include "ft_printf.h"

int		countflags(char *str)
{
	int		i;
	int		count;
	int		open_flag;
	i = 0;
	count = 0;
	open_flag = 0;

	while (str[i])
	{
		if(str[i] == '%')
		{
			count++;
			open_flag = 1;
			i++;
		}
		if ((str[i] == 's' || str[i] == 'S' || str[i] == 'p' || str[i] == 'd' ||
		str[i] == 'D' || str[i] == 'i' || str[i] == 'o' || str[i] == 'O' ||
		str[i] == 'u' || str[i] == 'U' || str[i] == 'x' || str[i] == 'X' ||
		str[i] == 'c' || str[i] == 'C' || str[i] == '%') && open_flag == 1)
		{
			open_flag = 0;
		}
		i++;
	}
	return(count);
}

char	**flagsplit(char *str)
{
	char	**ret;
	int		flag_nb;
	int		flag_len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	flag_nb = countflags(str);
	ret = (char **)malloc(sizeof(char *) * flag_nb + 1);
	while (i < flag_nb)
	{
		ret[i] = (char *)malloc(sizeof(char) * flag_len + 1);
		ret[i] = ft_strsub(str,j,flag_len);
		j = j + flag_len;
		i++;
	}
	return(ret);
}




int		main(int argc, char **argv)
{
	ft_putnbr(countflags(argv[1]));
}
