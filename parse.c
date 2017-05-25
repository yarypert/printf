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

void	first_check(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != 's' && str[i] != 'S' && str[i] != 'p' &&
		str[i] != 'd' && str[i] != 'D' && str[i] != 'i' && str[i] != 'o' &&
		str[i] != 'O' && str[i] != 'u' && str[i] != 'U' && str[i] != 'x' &&
		str[i] != 'h' && str[i] != 'l' && str[i] != 'j' && str[i] != 'z' &&
		str[i] != '#' && str[i] != '-' && str[i] != '+' && str[i] != '0' &&
		str[i] != 'X' && str[i] != 'c' && str[i] != 'C' && str[i] != '%')
		{
			ft_putendl("invalid format");
			exit(0);
		}
		i++;
	}
}

char **parse_format(char *str, va_list *args)
{
	int i = 0;
	char	**flags;
	int		count = 0;
	
	//count = count_flags(str);
	flags = ft_strsplit(str,'%');
	while(flags[i])
	{
		count++;
		i++;
	}
	i = 0;
	while (i < count)
	{
		dispatcher(flags[i], args);
		i++;
	}
	return (flags);
}
