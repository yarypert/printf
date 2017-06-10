/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 14:26:24 by yarypert          #+#    #+#             */
/*   Updated: 2017/06/10 14:37:29 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	printf("coucou%s%d%c%c", "test", 42, '0', 'a');
	printf("\n");
	printf("ft_printf =\n");
	ft_printf("coucou%s%d%c%c", "test", 42, '0', 'a');
	printf("\n");
	printf("\n");
return (0);
}
