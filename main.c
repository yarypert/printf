/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 14:26:24 by yarypert          #+#    #+#             */
/*   Updated: 2017/07/27 18:32:24 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int main(void)
{
	setlocale(LC_ALL, "");
	printf("test multiflags\n");
	printf("printf =\n");
	printf("%.4s\n", "coucou");
	printf("ft_printf =\n");
	ft_printf("%.4s\n", "coucou");
return (0);}
