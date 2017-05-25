/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 03:53:47 by yarypert          #+#    #+#             */
/*   Updated: 2017/05/16 14:50:26 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	int		ret;
	va_list args;

	ret = 0;
	if (format)
	{
		va_start(args, format);
		ret = analyse(&args, (char *)format);
		va_end(args);
	}
	return(ret);
}
