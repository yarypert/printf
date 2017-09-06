/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 14:39:17 by yarypert          #+#    #+#             */
/*   Updated: 2017/09/06 14:39:28 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft.h"

char	*ft_strappend(char *str1, char *str2)
{
	char*tmp;

	if (str1 && str2)
	{
		tmp = ft_strjoin(str1, str2);
		free(str1);
		return (tmp);
	}
	return (NULL);
}
