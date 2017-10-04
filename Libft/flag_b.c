/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 23:23:04 by yarypert          #+#    #+#             */
/*   Updated: 2017/10/04 01:27:21 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	flag_b(t_env *env, t_lst *lst)
{
	if (lst->preci != -1)
		flag_b_preci(env, lst);
	else
		flag_b_nopreci(env, lst);
	if(ft_strcmp(lst->indic , "-") == 0)
		lst->larg = ft_strjoin("-", lst->larg);
	lst->str = ft_strreplace(lst->str, lst->str,
			ft_largeur(ft_atoi(lst->larg), lst->str, lst));
}

void	flag_b_preci(t_env *env, t_lst *lst)
{
	if(lst->mode_l == 1)
		lst->str = ft_strreplace(lst->str, lst->str, precision_int
			(ft_ltoa_base(va_arg(env->args, long int), 2), lst->preci));
	if(lst->mode_l == 2 || lst->mode_j == 1)
		lst->str = ft_strreplace(lst->str, lst->str, precision_int
			(ft_ltoa_base(va_arg(env->args, long long int), 2), lst->preci));
	else
		lst->str = ft_strreplace(lst->str, lst->str, precision_int
				(ft_itoa_base(va_arg(env->args, int), 2), lst->preci));
}

void	flag_b_nopreci(t_env *env, t_lst *lst)
{
	if(lst->mode_l == 1)
		lst->str = ft_strreplace(lst->str, lst->str,
			ft_ltoa_base(va_arg(env->args, long int), 2));
	if(lst->mode_l == 2 || lst->mode_j == 1)
		lst->str = ft_strreplace(lst->str, lst->str,
			ft_ltoa_base(va_arg(env->args, long long int), 2));
	else
		lst->str = ft_strreplace(lst->str, lst->str,
				ft_itoa_base(va_arg(env->args, int), 2));
}
