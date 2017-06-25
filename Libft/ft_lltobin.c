/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lltobin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 01:14:57 by yarypert          #+#    #+#             */
/*   Updated: 2017/06/25 12:25:51 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static long long	long_long_power(long long nb, long long power)
{
	if (power < 0)
		return (0);
	else if (power < 1)
		return (1);
	else
		return (nb * long_long_power(nb, power - 1));
}

static char		*sub_bin(char *str)
{
	int		i;
	char	*ret;

	i = 0;
	while (str[i])
	{
		if (str[i] == '1')
			break ;
		i++;
	}
	ret = ft_strsub(str, i, ft_strlen(str));
	return (ret);
}

char		*ft_lltobin(long long nb)
{
	int		count;
	char	*ret;
	int		i;
	int		stock;

	stock = nb;
	i = 0;
	count = 63;
	if (nb < 0)
		nb = nb * (-1);
	ret = (char *)malloc(sizeof(char) * 63 + 1);
	while (count--)
	{
		if (nb >= long_long_power(2, count))
		{
			ret[i++] = '1';
			nb -= long_long_power(2, count);
		}
		else
			ret[i++] = '0';
	}
	ret = sub_bin(ret);
	if (stock < 0)
		ret = ft_strjoin("-", ret);
	return (ret);
}
