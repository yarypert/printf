#include "includes/ft_printf.h"

char	*precision_string(char *str, int prec)
{
	int i;
	char *str2;
	i = 0;
	if(prec < 0)
		return(0);
	if(!(str2 = (char *)malloc(sizeof(char) * prec + 1)))
		return(NULL);
	while (i < prec)
	{
		str2[i] = str[i];
		i++;
	}
	return(str2);
}

char	*precision_int(char *nb_str, int prec)
{
	char *nb_str2;
	int compl;
	int i;
	i = 0;
	if (prec < 0)
		return(nb_str);
	if (ft_strlen(nb_str) < prec)
		compl = prec - ft_strlen(nb_str);
	else
		return(nb_str);
	nb_str2 = (char *)malloc(sizeof(char) * compl);
	while (i < compl)
	{
		nb_str2[i] = '0';
		i++;
	}
	return(ft_strjoin(nb_str2, nb_str));
}
/*
int		main(int argc, char **argv)
{
	ft_putstr(precision_int(argv[1], ft_atoi(argv[2])));
	return 0;
}
*/
int main(int argc, char **argv)
{
	ft_putstr(precision_string(argv[1], ft_atoi(argv[2])));
	return 0;
}
