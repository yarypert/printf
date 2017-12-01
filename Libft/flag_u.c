/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 00:15:58 by yarypert          #+#    #+#             */
/*   Updated: 2017/12/01 06:14:19 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	flag_u(t_env *env, t_lst *lst)
{
	if (lst->preci != -1)
		flag_u_preci(env, lst);
	else
		flag_u_nopreci(env, lst);
	if (ft_strcmp(lst->indic, "-") == 0)
		lst->larg = ft_strjoin("-", lst->larg);
	lst->str = ft_strlowcase(ft_strreplace(lst->str,
				lst->str, ft_largeur(ft_atoi(lst->larg), lst->str, lst)));
}

void	flag_u_preci(t_env *env, t_lst *lst)
{
	if (lst->mode_l == 1)
		lst->str = ft_strreplace(lst->str, lst->str,
				precision_int(ft_ultoa_base(va_arg(env->args, unsigned long int), 10), lst->preci));
	else if (lst->mode_l == 2 || lst->mode_j == 1 || lst->mode_z == 1)
		lst->str = ft_strreplace(lst->str, lst->str,
				precision_int(ft_ultoa_base(va_arg(env->args, unsigned long long int), 10), lst->preci));
	else
		lst->str = ft_strreplace(lst->str, lst->str,
				precision_int(ft_ultoa_base(va_arg(env->args, unsigned int), 10), lst->preci));
}

void	flag_u_nopreci(t_env *env, t_lst *lst)
{
	if (lst->mode_l == 1)
		lst->str	 = ft_strreplace(lst->str, lst->str,
				ft_ultoa_base(va_arg(env->args, unsigned long int), 10));
	else if (lst->mode_l == 2 || lst->mode_j == 1 || lst->mode_z == 1)
		lst->str = ft_strreplace(lst->str, lst->str,
				ft_ultoa_base(va_arg(env->args, unsigned long long int), 10));
	else
		lst->str = ft_strreplace(lst->str, lst->str,
				ft_ultoa_base(va_arg(env->args, unsigned int), 10));
}
