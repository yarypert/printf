/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:19:52 by ygaude            #+#    #+#             */
/*   Updated: 2018/01/06 23:58:06 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				ft_strlcat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	start;

	start = ft_strnlen(s1, n);
	if (n == start)
		return (n + ft_strlen(s2));
	i = 0;
	while (s2[i])
	{
		if (start + i < n - 1)
			s1[i + start] = s2[i];
		i++;
	}
	if (i + start < n)
		s1[i + start] = '\0';
	else
		s1[n - 1] = '\0';
	return (start + i);
}
