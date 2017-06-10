#include "libft.h"
#include "math.h"
#include <stdio.h>


char    *ft_strjoin_free(char **s1, char **s2)
{
	char	*new;
	size_t	len;

	len = ft_strlen(*s1) + ft_strlen(*s2) + 1;
	if (!s1 || !s2 || !(new = ft_strnew(len)))
		return (0);
	ft_strcat(new, *s1);
	ft_strcat(new, *s2);
    ft_strdel(s1);
    ft_strdel(s2);
	new[len] = '\0';
	return (new);
}

char	*ft_strset(int len, char c)
{
	char	*dest;
	int		i;

	i = 0;
	len--;
	if (!(dest = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	while (i < len)
	{
		dest[i] = c;
		i++;
	}
	dest[i] = '\0';
	return(dest);
}

char	*ft_ftoa(double n, int i)
{
	char	*l_zero;
	int		pos;
	char	*ptr;
	char	*ret;
	double	dec;

	pos = (n < 0) ? 1 : 0;
	ret = ft_itoa(n);
	if (i == 0)
		return (ret);
	ptr = ft_strdup(".");
	ret = ft_strjoin_free(&ret, &ptr);
	n *= pos ? -1 : 1;
	dec = n - (int)n;
	while (dec)
	{
		i--;
		if (i < 0)
		{
			if ((dec - (int)dec) * 10 > 5)
				dec += (pos ? 1 : -1);
			break;
		}
		dec *= 10;

	}
	ptr = ft_itoa((int)dec);
	ret = ft_strjoin_free(&ret, &ptr);
	if (i == 0)
	{
		l_zero = ft_strset(i, '0');
		ret = ft_strjoin_free(&ret, &l_zero);
	}
	return (ret);
}

int main(void)
{
	ft_putendl(ft_ftoa(1.000000, 1));
	printf("%1.1f\n", 1.0000000);
    return (0);
}
