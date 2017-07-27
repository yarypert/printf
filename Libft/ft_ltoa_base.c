/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 19:46:38 by yarypert          #+#    #+#             */
/*   Updated: 2017/07/27 13:27:24 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count(unsigned long int n, int base)
{
	int			i;

	i = 1;
	while (n / base)
	{
		n /= base;
		i++;
	}
	return (i);
}

void	ft_str_fill(char *str, unsigned long int n, int base)
{
	int			digit;

	if (n / base)
		ft_str_fill(str - 1, n / base, base);
	digit = n % base;
	if (digit < 10)
		*str = digit + '0';
	else
		*str = digit - 10 + 'A';
}

char	*ft_ltoa_base(long int value, int base)
{
	unsigned int	n;
	int				neg;
	int				i;
	char			*str;

	if (base < 2 || base > 16)
		return (NULL);
	neg = (base == 10 && value < 0) ? 1 : 0;
	n = (value < 0) ? -value : value;
	i = ft_count(n, base);
	str = (char *)malloc(sizeof(char) * (i + neg + 1));
	if (neg)
		str[0] = '-';
	ft_str_fill(str + i + neg - 1, n, base);
	str[i + neg] = '\0';
	return (str);
}
