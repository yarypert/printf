/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 14:26:24 by yarypert          #+#    #+#             */
/*   Updated: 2017/07/31 09:38:46 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int main(void)
{
	setlocale(LC_ALL, "");
	printf("test multiflags\n");
	printf("printf =\n");
	printf("%3s\n", "prout");
	printf("%.3s\n", "prout");
	printf("ft_printf =\n");
	ft_printf("%3s\n", "prout");
	ft_printf("%.3s\n", "prout");
return (0);}
