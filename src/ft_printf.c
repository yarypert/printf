/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 04:26:18 by yarypert          #+#    #+#             */
/*   Updated: 2018/01/07 04:26:51 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"
#include "../libft/libft.h"

int		ft_vasprintf(char **ret, const char *format, va_list ap)
{
	t_str	fmt;
	t_str	res;
	int		error;

	error = 0;
	fmt.str = (char *)format;
	res = ft_loop(fmt, ap, &error);
	*ret = res.str;
	return ((error) ? -1 : res.len);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*str;
	int		ret;

	va_start(ap, format);
	ret = ft_vasprintf(&str, format, ap);
	if (ret != -1)
		write(1, str, ret);
	ft_strdel(&str);
	va_end(ap);
	return (ret);
}
