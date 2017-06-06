#include "ft_printf.h"

int		is_close(char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' ||
			c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'U' ||
			c == 'x' || c == 'X' || c == 'c' || c == 'C' || c == '%')
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
		ret[i] = ft_strsub(str, j, flag_len[i]);
		j = j + flag_len[i];
		i++;
	}
	return(ret);
}

int		recount(char **str ,int flag_nb)
{
	int i = 0;
	int j;
	int recount = 0;
	int openstr;
	int openperc;
	while (i < flag_nb)
	{
		j = 0;
		if(str[i][0] == '%')
		{
			openperc = 1;
			openstr = 0;
		}
		else
		{
			openstr = 1;
			openperc = 0;
			recount++;
		}
		while (str[i][j])
		{
			if (str[i][j] != '#' && str[i][j] != '0' && str[i][j] != '-' && str[i][j] != '+')
			{
				if (!((is_close(str[i][j])) && (str[i][j-1] == '#' || str[i][j-1] == '-' || str[i][j-1] == '+' || str[i][j-1] == '0')))
				{
					if(openperc == 0 && openstr == 0 && str[i][j] != '%')
					{
						openstr = 1;
						recount++;
					}
					if(openperc == 1 && is_close(str[i][j]))
					{
						openperc = 0;
						recount++;
						j++;
					}
					if(openstr == 1 && (str[i][j + 1] == '%'))
					{
						openstr = 0;
						recount++;
					}
				}
			}
			j++;
		}
		i++;
	}
	return(recount);
}

int		*relen(char **str ,int flag_nb, int *relen_flag)
{
	int i = 0;
	int j;
	int k = 0;
	int l = 0;
	int openstr;
	int openperc;
	while (i < flag_nb)
	{
		j = 0;
		if(str[i][0] == '%')
		{
			openperc = 1;
			openstr = 0;
		}
		else
		{
			openstr = 1;
			openperc = 0;
			relen_flag[k] = l;
			k++;
		}
		while (str[i][j])
		{
			if (str[i][j] != '#' && str[i][j] != '0' && str[i][j] != '-' && str[i][j] != '+')
			{
				if (!((is_close(str[i][j])) && (str[i][j-1] == '#' || str[i][j-1] == '-' || str[i][j-1] == '+' || str[i][j-1] == '0')))
				{
					if(openperc == 0 && openstr == 0 && str[i][j] != '%')
					{
						openstr = 1;
						relen_flag[k] = l;
						k++;
					}
					if(openperc == 1 && is_close(str[i][j]))
					{
						openperc = 0;
						relen_flag[k] = l;
						k++;
						j++;
						l++;
					}
					if(openstr == 1 && (str[i][j + 1] == '%'))
					{
						openstr = 0;
						relen_flag[k] = l + 1;
						k++;
					}
				}
			}
			j++;
			l++;
		}
		i++;
	}
	return(relen_flag);
}

char	**reflagsplit(char *str,int flag_nb,int *flag_len)
{
	char	**ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ret = (char **)malloc(sizeof(char *) * flag_nb + 1);
	while (i < flag_nb)
	{
		ret[i] = (char *)malloc(sizeof(char) * flag_len[i] + 1);
		ret[i] = ft_strsub(str, j, flag_len[i]);
		j = j + flag_len[i];
		i++;
	}
	return(ret);
}

int		main(int argc, char **argv)
{
	int flag_nb;
	char **tab;
	int *flag_len;
	int recount_flag;
	int *relen_flag;
	flag_nb = countflags(argv[1]);
	flag_len = lenflags(argv[1], flag_nb);
	flag_len = lenflags2(argv[1], flag_len, flag_nb);
	tab = flagsplit(argv[1]);

	int i = 0;
	while (i < flag_nb)
	{
		ft_putendl(tab[i]);
		i++;
	}

	recount_flag = recount(tab, flag_nb);
	relen_flag = (int *)malloc(sizeof(int) * recount_flag);
	relen_flag = relen(tab, flag_nb, relen_flag);
	relen_flag = lenflags2(argv[1], relen_flag, recount_flag);
	tab = reflagsplit(argv[1], recount_flag, relen_flag);


	ft_putnbr(recount_flag);
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putchar('\n');
	i = 0;
	while (i < recount_flag)
	{
		ft_putnbr(relen_flag[i]);
		ft_putchar('\n');
		i++;
	}
	ft_putchar('\n');
	ft_putchar('\n');

	i = 0;
	while (i < recount_flag)
	{
		ft_putendl(tab[i]);
		i++;
	}
}
