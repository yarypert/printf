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
	ft_putendl("test %s");
	ft_putstr("printf =\n");
	dprintf(1, "%s", "le test est reussi");
	ft_putchar('\n');
	ft_putstr("ft_printf =\n");
	ft_printf("%s", "le test est reussi");
	ft_putchar('\n');
	ft_putchar('\n');

	ft_putendl("test %d");
	ft_putstr("printf =\n");
	dprintf(1, "%d", 42);
	ft_putchar('\n');
	ft_putstr("ft_printf =\n");
	ft_printf("%d", 42);
	ft_putchar('\n');
	ft_putchar('\n');

	ft_putendl("test %c");
	ft_putstr("printf =\n");
	dprintf(1, "%c", 'a');
	ft_putchar('\n');
	ft_putstr("ft_printf =\n");
	ft_printf("%c", 'a');
	ft_putchar('\n');
	ft_putchar('\n');

	ft_putendl("test %c 2");
	ft_putstr("printf =\n");
	dprintf(1, "%c", 48);
	ft_putchar('\n');
	ft_putstr("ft_printf =\n");
	ft_printf("%c", 48);
	ft_putchar('\n');
	ft_putchar('\n');

	ft_putendl("test multiflags");
	ft_putstr("printf =\n");
	dprintf(1, "coucou%s%d%c", "test", 42, '0');
	ft_putchar('\n');
	ft_putstr("ft_printf =\n");
	ft_printf("coucou%s%d%c", "test", 42, '0');
	ft_putchar('\n');
	ft_putchar('\n');
return (0);
}
