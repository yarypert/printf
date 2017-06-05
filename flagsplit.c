#include "ft_printf.h"

int		is_close(char c)
{
		if (c == 's' || c == 'S' || c == 'p' || c == 'd' ||
		c == 'D' || c == 'i' || c == 'o' || c == 'O' ||
		c == 'u' || c == 'U' || c == 'x' || c == 'X' ||
		c == 'c' || c == 'C' || c == '%')
			return(1);
		return(0);
}


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
		if (is_close(str[i]) && open_flag == 1)
		{
			open_flag = 0;
		}
		i++;
	}
	return(count);
}

int		*lenflags(char *str, int count)
{
	int		i;
	int		j;
	int		*len;
	int		open_flag;
	i = 0;
	j = 0;
	len = (int *)malloc(sizeof(int) * count);
	open_flag = 0;

	while (str[i])
	{
		if(str[i] == '%')
		{
			len[j] = i;
			open_flag = 1;
			j++;
			i++;
		}
		if (is_close(str[i]) && open_flag == 1)
		{
			open_flag = 0;
		}
		i++;
	}
	return(len);
}

int		*lenflags2(char *str, int *len, int count)
{
	int i = 0;
	int *len2 = len;

	while (i < count)
	{
		len2[i] = len[i + 1];
		i++;
	}
	i = count - 1;
	len2[i] = ft_strlen(str);
	while (i > 0)
	{
		len2[i] = len2[i] - len2[i - 1];
		i--;
	}
	return(len2);
}

char	**flagsplit(char *str)
{
	char	**ret;
	int		flag_nb;
	int		*flag_len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	flag_nb = countflags(str);
	flag_len = lenflags(str, flag_nb);
	flag_len = lenflags2(str, flag_len, flag_nb);
	ret = (char **)malloc(sizeof(char *) * flag_nb + 1);
	while (i < flag_nb)
	{
		ret[i] = (char *)malloc(sizeof(char) * flag_len[i] + 1);
		ret[i] = ft_strsub(str,j,flag_len[i]);
		j = j + flag_len[i];
		i++;
	}
	return(ret);
}

char	**resplit(char **str, int flag_nb, int *flag_len)
{
}

int		main(int argc, char **argv)
{
	int flag_nb;
	char **tab;
	flag_nb = countflags(argv[1]);
	tab = flagsplit(argv[1]);
	int i = 0;
	while (i < flag_nb)
	{
		ft_putendl(tab[i]);
		i++;
	}
}
