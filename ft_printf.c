/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 03:53:47 by yarypert          #+#    #+#             */
/*   Updated: 2017/06/09 01:37:13 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	int		ret;
	t_env	env;
	ret = 0;
	if (format)
	{
		va_start(env.args, format);

//       !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

		va_end(env.args);
	}
	return(ret);
}
