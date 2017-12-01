/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 23:06:58 by yarypert          #+#    #+#             */
/*   Updated: 2017/12/01 03:55:04 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	flag_p(t_env *env, t_lst *lst)
{
	lst->xvalue = va_arg(env->args, unsigned long long int);
	lst->str = ft_strreplace(lst->str, lst->str, ft_ultoa_base((unsigned long long int)lst->xvalue, 16));
	lst->str = ft_strlowcase(ft_strjoin("0x", lst->str));
}
