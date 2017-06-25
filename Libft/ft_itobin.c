/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itobin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 14:05:51 by yarypert          #+#    #+#             */
/*   Updated: 2017/06/25 12:25:31 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int			int_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power < 1)
		return (1);
	else
		return (nb * int_power(nb, power - 1));
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

char		*ft_itobin(int nb)
{
	int		count;
	char	*ret;
	int		i;
	int		stock;

	stock = nb;
	i = 0;
	count = 31;
	if (nb < 0)
		nb = nb * (-1);
	ret = (char *)malloc(sizeof(char) * 31 + 1);
	while (count--)
	{
		if (nb >= int_power(2, count))
		{
			ret[i++] = '1';
			nb -= int_power(2, count);
		}
		else
			ret[i++] = '0';
	}
	ret = sub_bin(ret);
	if (stock < 0)
		ret = ft_strjoin("-", ret);
	return (ret);
}
