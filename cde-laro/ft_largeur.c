#include "../Libft/libft.h"

char    *ft_strjoin_free(char *s1, char *s2)
{
    char	*new;
    size_t	len;

    len = ft_strlen(s1) + ft_strlen(s2) + 1;
    if (!s1 || !s2 || !(new = ft_strnew(len)))
        return (0);
    ft_strcat(new, s1);
    ft_strcat(new, s2);
    //free(s1);
    //free(s2);
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

char *ft_largeur(int largeur, char *str)
{
    int     neg;
    int     len;
	char	*dest;
	char	*src;

    if (largeur < 0)
    {
        largeur *= -1;
        neg = 1;
    }
    else
        neg = 0;
    if ((len = strlen(str)) > largeur)
        return (str);
    if (neg)
        return(ft_strjoin(str, ft_strset(largeur - len + 1, ' ')));
    else
        return(ft_strjoin(ft_strset(largeur - len + 1, ' '), str));
}

int		main(int argc, char **argv)
{
    printf("%-5.f\n", 0.01);
    printf("%s\n", ft_largeur(-5, "0.01"));
    return (0);
}
