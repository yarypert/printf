/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 03:53:47 by yarypert          #+#    #+#             */
/*   Updated: 2017/09/27 12:56:31 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_printf(const char *format, ...)
{
	t_env	env;
	env.ret = 0;
	env.format = (char *)format;
	t_lst	*lst;
	lst = NULL;
	if (format)
	{
		va_start(env.args, format);
		env.ret = process(&env, lst);
		va_end(env.args);
	}
	return(env.ret);
}
