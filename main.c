/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 14:26:24 by yarypert          #+#    #+#             */
/*   Updated: 2017/07/27 16:49:00 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int main(void)
{
	setlocale(LC_ALL, "");
	printf("test s\n");
	printf("printf =\n");
	printf("%s", "le test est reussi");
	printf("\n");
	printf("ft_printf =\n");
	ft_printf("%s", "le test est reussi");
	printf("\n");
	printf("\n");

	printf("test d\n");
	printf("printf =\n");
	printf("%d", 42);
	printf("\n");
	printf("ft_printf =\n");
	ft_printf("%d", 42);
	printf("\n");
	printf("\n");

	printf("test c\n");
	printf("printf =\n");
	printf("%c", 'a');
	printf("\n");
	printf("ft_printf =\n");
	ft_printf("%c", 'a');
	printf("\n");
	printf("\n");

	printf("test c 2\n");
	printf("printf =\n");
	printf("%c", 48);
	printf("\n");
	printf("ft_printf =\n");
	ft_printf("%c", 48);
	printf("\n");
	printf("\n");

	printf("test multiflags\n");
	printf("printf =\n");
	printf("coucou %s %d %c %c %x %o", "test", 42, '0', 'a', 2485, 18);
	printf("\n");
	printf("ft_printf =\n");
	ft_printf("coucou %s %d %c %c %x %o %b", "test", 42, '0', 'a', 2485, 18, 12542);
	printf("\n");
	printf("\n");

return (0);}
