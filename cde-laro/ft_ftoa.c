/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 14:48:50 by cde-laro          #+#    #+#             */
/*   Updated: 2017/06/25 14:51:01 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "math.h"
#include <stdio.h>

char    *ft_strjoin_free(char *s1, char *s2)
{
	char	*new;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!s1 || !s2 || !(new = ft_strnew(len)))
		return (0);
	ft_strcat(new, s1);
	ft_strcat(new, s2);
    free(s1);
    free(s2);
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
	char	*ret;
	double	dec;
	int		ibis;

	if (i == 0)
		return(ft_itoa(n));
	ibis = i;
	pos = (n < 0) ? 1 : 0;
	n *= pos ? -1 : 1;
	dec = n - (int)n;
	while (dec && i-- > 0)
		dec *= 10;
	if (dec - (int) dec > 0.5)
		dec++;
	if (dec >= ft_power(10, ibis))
	{
		n++;
		dec = 0;
		i = ibis;
	}
	ret = ft_itoa((int)n * (pos ? -1 : 1));
	ret = ft_strjoin_free(ft_strjoin_free(ret, ft_strdup(".")), ft_itoa((int)dec));
	if (i > 0)
	{
		l_zero = ft_strset(i, '0');
		ret = ft_strjoin_free(ret, l_zero);
	}
	return (ret);
}

/* int main(void)
{
	ft_putstr("ft_printf: \t");
	ft_putendl(ft_ftoa(-1.99999999, 5));
	printf("printf: \t%1.5f\n", -1.99999999);
    return (0);
}
*/
