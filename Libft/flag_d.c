/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 23:07:43 by yarypert          #+#    #+#             */
/*   Updated: 2017/10/03 23:08:35 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	flag_d(t_env *env, t_lst *lst)
{
	if (lst->preci != -1)
	{
		if (lst->	mode_l == 1)
			lst->str = ft_strreplace(lst->str, lst->str,
					precision_int(ft_ltoa(va_arg(env->args, long int)), lst->preci));
		else if (lst->mode_l == 2 || lst->mode_j == 1)
			lst->str = ft_strreplace(lst->str, lst->str,
					precision_int(ft_ltoa(va_arg(env->args, long long int)), lst->preci));
		else
			lst->str = ft_strreplace(lst->str, lst->str,
					precision_int(ft_itoa(va_arg(env->args, int)), lst->preci));
	}
	else
	{
	if (lst->mode_l == 1)
		lst->str = ft_strreplace(lst->str, lst->str,
				ft_itoa(va_arg(env->args, long int)));
	else if (lst->mode_l == 2 || lst->mode_j == 1)
		lst->str = ft_strreplace(lst->str, lst->str,
				ft_ltoa(va_arg(env->args, long long int)));
	else
		lst->str = ft_strreplace(lst->str, lst->str,
				ft_ltoa(va_arg(env->args, int)));
	}
	if (ft_strcmp(lst->indic, "-") == 0)
		lst->larg = ft_strjoin("-", lst->larg);
	lst->str = ft_strreplace(lst->str, lst->str,
			ft_largeur(ft_atoi(lst->larg), lst->str, lst));
}
