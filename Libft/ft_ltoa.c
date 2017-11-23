/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 01:01:22 by yarypert          #+#    #+#             */
/*   Updated: 2017/11/23 13:21:49 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	itoa_islongnegative(long int *n, int *negative)
{
	if (*n < 0)
	{
		*n	*= -1;
		*negative = 1;
	}
}

char	*ft_ltoa(long int n)
{
	unsigned long int		tmpn;
	int		negative;
	char	*str;
	long int len;

	if(n == -2147483647 - 1)
		return(ft_strdup("-2147483648"));
	len = 2;
	negative = 0;
	itoa_islongnegative(&n, &negative);
	tmpn = n;
	while (tmpn /= 10)
		len++;
	len += negative;
	if ((str = (char*)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	if (negative)
		str[0] = '-';
	return (str);
}
