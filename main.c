/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 14:26:24 by yarypert          #+#    #+#             */
/*   Updated: 2017/05/16 15:45:13 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(void)
{
	ft_printf("%-d%-s%-x", 25, "coucou", 255);
	ft_printf("%-%\n\n%-s%-x", 25, "coucou", 255);
	ft_printf("%d%s%x", 25, "coucou", 255);
	ft_printf("%d%s%x%s%s%d");
	ft_printf("%d", 25);
	ft_printf("%s","coucou");
	ft_printf("%%%d");
	return (0);
}
