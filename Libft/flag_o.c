/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 23:09:39 by yarypert          #+#    #+#             */
/*   Updated: 2017/11/18 18:38:40 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	flag_o(t_env *env, t_lst *lst)
{
	if(lst->preci == 0)
		lst->str = ft_strreplace(lst->str,
				lst->str, ft_largeur(ft_atoi(lst->larg), "", lst));
	else
	{
		if (lst->preci != -1)
			flag_o_preci(env, lst);
		else
			flag_o_nopreci(env, lst);
		if (ft_strchr(lst->indic, '-') != 0)
		{
			lst->larg_c = 0;
			lst->larg = ft_strjoin("-", lst->larg);
		}
		lst->str = ft_strreplace(lst->str,
				lst->str, ft_largeur(ft_atoi(lst->larg), lst->str, lst));
	}
}

void	flag_o_preci(t_env *env, t_lst *lst)
{
	if (lst->mode_l == 1)
		lst->str = ft_strreplace(lst->str, lst->str,
				precision_int(ft_ultoa_base(va_arg(env->args, unsigned long int), 8), lst->preci));
	else if (lst->mode_l == 2 || lst->mode_j == 1)
		lst->str = ft_strreplace(lst->str, lst->str,
				precision_int(ft_ultoa_base(va_arg(env->args, unsigned long long int), 8), lst->preci));
	else
		lst->str = ft_strreplace(lst->str, lst->str,
				precision_int(ft_ultoa_base(va_arg(env->args, unsigned int), 8),
					lst->preci));
}

void	flag_o_nopreci(t_env *env, t_lst *lst)
{
	if (lst->mode_l == 1)
		lst->str = ft_strreplace(lst->str, lst->str,
				ft_ultoa_base(va_arg(env->args, unsigned long int), 8));
	else if (lst->mode_l == 2 || lst->mode_j == 1)
		lst->str = ft_strreplace(lst->str, lst->str,
				ft_ultoa_base(va_arg(env->args, unsigned long long int), 8));
	else
		lst->str = ft_strreplace(lst->str, lst->str,
				ft_ultoa_base(va_arg(env->args, unsigned int), 8));
}
