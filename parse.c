/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 14:48:49 by yarypert          #+#    #+#             */
/*   Updated: 2017/05/16 15:45:17 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		count_flags(char *str)
{
	int i;
	int count;
	int close;

	i = 0;
	count = 0;
	close = 1;
	while (str[i])
	{
		if (str[i] == '%' && close == 1)
		{
			close = 0;
			count++;
		}
		else if (str[i] == 's' || str[i] == 'S' || str[i] == 'p' ||
		str[i] == 'd' || str[i] == 'D' || str[i] == 'i' || str[i] == 'o' ||
		str[i] == 'O' || str[i] == 'u' || str[i] == 'U' || str[i] == 'x' ||
		str[i] == 'X' || str[i] == 'c' || str[i] == 'C' || str[i] == '%')
			close = 1;
		else
		{
			close = 1;
			i++;
		}
		i++;
	}
	return (count);
}

char **parse_format(char *str)
{
	char	**flags;
	int		count;
	
	ft_putnbr(count_flags(str));
	ft_putchar(' ');
	ft_putstr(str);
	ft_putchar('\n');
	flags = ft_strsplit(str,'%');

	return (flags);
}
