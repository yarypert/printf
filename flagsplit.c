#include "ft_printf.h"

int		countflags(char *str)
{
	int i;
	i = 0;
	int count;
	int flag;
	int open_flag;
	flag = 0;
	count = 0;
	open_flag = 0;
	while (str[i])
	{
		if(flag == 0)
		{
			flag = 1;
			count++;
		}
		if(str[i] == '%')
		{
			count++;
			open_flag = 1;
		}
		if((str[i] == 's' || str[i] == 'S' || str[i] == 'p' || str[i] == 'd' ||
		str[i] == 'D' || str[i] == 'i' || str[i] == 'o' || str[i] == 'O' ||
		str[i] == 'u' || str[i] == 'U' || str[i] == 'x' || str[i] == 'X' ||
		str[i] == 'c' || str[i] == 'C' || str[i] == '%') && open_flag == 1)
		{
			open_flag = 0;
		}
		i++;
	}
	if(str[0] == '%')
		return(count - 1);
	return(count);
}

int		count_flag_len(char *str,int start)
{
	
}

char	**flagsplit(char *str)
{
	char **ret;
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
		flag_len = count_flag_len(str, j);
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
