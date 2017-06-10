/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yolo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <aancel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 02:49:45 by aancel            #+#    #+#             */
/*   Updated: 2017/06/10 19:17:58 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		main(void)
{
	char *str;

	str = ft_strjoin(FLAG_C, FCOL_GREY);
	ft_putstr(str);
	ft_putwchar(0x1f427);
	ft_putstr("  ");
	ft_putwchar(0x1f419);
	ft_putendl(" " FIN);
	// printf("nombre x = %o, nombre y = %d\n", 4, 6);
	return (0);
}
