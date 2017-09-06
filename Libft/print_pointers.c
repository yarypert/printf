/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 14:52:16 by yarypert          #+#    #+#             */
/*   Updated: 2017/09/06 14:53:02 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_nbrhexlen(int cp)
{
	int i;

	i = 0;
	while (cp > 0)
	{
		cp /= 16;
		i++;
	}
	return (i);
}

char	*ft_putpp(void *p)
{
	char *hex;
	char *ref;
	int nbr;
	int i;
	char *fin;

	i = 0;
	hex = "0x7fff";
	ref = "0123456789abcdef";
	nbr = (int)p;
	i = ft_nbrhexlen(nbr);
	fin = (char *)malloc(sizeof(char) * (i + 1));
	fin[i] = '\0';
	i = 0;
	while (nbr > 0)
	{
		fin[i++] = ref[nbr % 16];
		nbr /= 16;
	}
	return (ft_strjoin(hex, ft_strrev(fin)));
}
