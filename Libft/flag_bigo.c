/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_bigo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 23:13:29 by yarypert          #+#    #+#             */
/*   Updated: 2017/10/04 03:25:30 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	flag_bigo(t_env *env, t_lst *lst)
{
	if (lst->preci != -1)
		flag_bigo_preci(env, lst);
	else
		flag_bigo_nopreci(env, lst);
	if (ft_strcmp(lst->indic, "-") == 0)
		lst->larg = ft_strjoin("-", lst->larg);
	lst->str = ft_strreplace(lst->str,
			lst->str, ft_largeur(ft_atoi(lst->larg), lst->str, lst));
}

void	flag_bigo_preci(t_env *env, t_lst *lst)
	{
		lst->str = ft_strreplace(lst->str, lst->str,
				precision_int(ft_ltoa_base(va_arg(env->args, long int), 8),
					lst->preci));
	}

void	flag_bigo_nopreci(t_env *env, t_lst *lst)
	{
		lst->str = ft_strreplace(lst->str, lst->str,
				ft_ltoa_base(va_arg(env->args, long int), 8));
	}
