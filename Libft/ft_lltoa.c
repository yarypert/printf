/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 01:01:22 by yarypert          #+#    #+#             */
/*   Updated: 2017/12/01 07:29:39 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	itoa_isllnegative(long long int *n, int *negative)
{
	if (*n < 0)
	{
		*n	*= -1;
		*negative = 1;
	}
}

char	*ft_lltoa(long long int n)
{
	unsigned long long int		tmpn;
	int		negative;
	char	*str;
	long int len;

	if(n == -9223372036854775807 - 1)
		return(ft_strdup("-9223372036854775808"));
	len = 2;
	negative = 0;
	itoa_isllnegative(&n, &negative);
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
