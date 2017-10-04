/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 23:05:37 by yarypert          #+#    #+#             */
/*   Updated: 2017/10/04 03:46:27 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	flag_s(t_env *env, t_lst *lst)
{
	if (lst->preci != -	1)
		flag_s_preci(env, lst);
	else
		flag_s_nopreci(env, lst);
	if (ft_strcmp(lst->indic, "-") == 0)
		lst->larg = ft_strjoin("-", lst->larg);
	lst->str = ft_strreplace(lst->str, lst->str, ft_largeur(ft_atoi(lst->larg),
				lst->str, lst));
}

void	flag_s_preci(t_env *env, t_lst *lst)
	{
		lst->str = ft_strreplace(lst->str, lst->str,
				precision_string(va_arg(env->args, char*), lst->preci));
	}

void	flag_s_nopreci(t_env *env, t_lst *lst)
	{
		lst->str = ft_strreplace(lst->str, lst->str,
				va_arg(env->args, char*));
	}
