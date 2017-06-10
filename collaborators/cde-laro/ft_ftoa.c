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
/*
static int	ft_len(long long int n)
{
	int len;

	len = 2;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 9)
	{
		len++;
		n = n / 10;
	}
	return (len);
}
*/

char	*ft_ftoa(double n, int i)
{
	//int		one;
	int		pos;
	char	*ptr;
	char	*ret;
	double	two;

	pos = (n < 0) ? 1 : 0;
	ret = ft_itoa(n);
	ptr = ft_strdup(".");
	ret = ft_strjoin_free(&ret, &ptr);
	n *= pos ? -1 : 1;
	//one = (int)n;
	two = n - (int)n;
	while ((++pos))
	{
		i--;
		if (i < 0)
		{
			if ((two - (int)two) * 10 > 5)
				two += (pos ? 1 : -1);
			break;
		}
		two *= 10;

	}
	ptr = ft_itoa((int)two);
	ret = ft_strjoin_free(&ret, &ptr);
	return (ret);
}

/*char    *ft_ftoa(float n, size_t comma)
{
    int     ent;
    float     dec;
    char    *dst;

    ent = (int)n;
    if (comma == 0)
        return (ft_itoa(ent));
    dec = (n - ent) * pow(10, comma);
	printf("(%f - %d) * %f = %f\n",n, ent, pow(10, comma), dec);
    if (!(dst = (char *)malloc(sizeof(char) * ft_len(ent) + comma + 2)))
        return (NULL);
    ft_strcpy(dst, ft_itoa(ent));
    ft_strcat(dst, ".");
	ft_strncat(dst, ft_itoa(dec), comma);
//	ft_putendl(dst);
//	ft_putnbr(dec);
	ft_putchar('\n');
    ft_memset(dst, '0', ft_len(ent) + comma + 2);

    return dst;
}*/

int main(void)
{
    ft_putendl(ft_ftoa(1.899999, 4));
	printf("%4.4f", 1.899999);
    return (0);
}
