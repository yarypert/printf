/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 16:00:32 by yarypert          #+#    #+#             */
/*   Updated: 2017/09/06 17:22:32 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	flag_o(t_env *env, t_lst *lst)
{
	if (lst->preci != -1)
	{
		lst->str = ft_strreplace(lst->str, lst->str, precision_int(ft_itoa_base
					(va_arg(env->args, int), 8), lst->preci));
	}
	else
	{
		lst->str = ft_strreplace(lst->str, lst->str, ft_itoa_base
				(va_arg(env->args, int), 8));
	}
}

void	flag_bigo(t_env *env, t_lst *lst)
{
	if (lst->preci != -1)
	{
		lst->str = ft_strreplace(lst->str, lst->str, precision_int(ft_ltoa_base
					(va_arg(env->args, long), 8), lst->preci));
	}
	else
	{
		lst->str = ft_strreplace(lst->str, lst->str, ft_ltoa_base
				(va_arg(env->args, long), 8));
	}
}

void	flag_bigu(t_env *env, t_lst *lst)
{
	if(lst->preci != -1)
	{
		lst->str = ft_strreplace(lst->str, lst->str, precision_int(ft_ltoa(va_arg(env->args,unsigned int)), lst->preci));
	}
	else
	{
		lst->str = ft_strreplace(lst->str, lst->str, ft_ltoa(va_arg(env->args, unsigned int)));
	}
}

void	flag_x(t_env *env, t_lst *lst)
{
	if (lst->preci != -1)
	{
		lst->str = ft_strreplace(lst->str, lst->str, precision_int(ft_strlowcase
					(ft_itoa_base(va_arg(env->args, int), 16)),lst->preci));
	}
	else
	{
		lst->str = ft_strreplace(lst->str, lst->str, ft_strlowcase
				(ft_itoa_base(va_arg(env->args, int), 16)));
	}
}

void	flag_bigx(t_env *env, t_lst *lst)
{
	if (lst->preci != -1)
	{
		lst->str = ft_strreplace(lst->str, lst->str, precision_int(ft_strupcase
					(ft_itoa_base(va_arg(env->args, long), 16)), lst->preci));
	}
	else
	{
		lst->str = ft_strreplace(lst->str, lst->str, ft_strupcase
				(ft_itoa_base(va_arg(env->args, long), 16)));
	}
}
