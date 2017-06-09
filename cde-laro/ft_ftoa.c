#include "libft.h"


/*char    *ft_strjoin_free_comma(char *s1, char *s2)
{
	char	*new;

	if (!s1 || !s2 || !(new = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 2)))
		return (0);
	ft_strcat(new, s1);
    ft_strcat(new, ",");
	ft_strcat(new, s2);
    ft_strdel(s1);
    ft_strdel(s2);
	new[ft_strlen(new)] = '\0';
	return (new);
}
*/
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


char    *ft_ftoa(float n, size_t comma)
{
    int     ent;
    int     dec;
    char    *dst;

    ent = (int)n;
    if (comma == 0)
        return (ft_itoa(ent));
    dec = (n - (float)ent) * pow(10, comma);
    if (!(dst = (char *)malloc(sizeof(char) * ft_len(ent) + comma + 2)))
        return (NULL);
    ft_putnbr(ent);
    ft_putchar(',');
    ft_putnbr((int)dec);
    ft_putstr("\n");
    ft_memset(dst, '0', ft_len(ent) + comma + 2);

    return dst;
}

int main(void)
{
    ft_ftoa(1.121, 6);
    return (0);
}
