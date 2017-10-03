/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 23:09:39 by yarypert          #+#    #+#             */
/*   Updated: 2017/10/03 23:12:05 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	flag_o(t_env *env, t_lst *lst)
{
	if (lst->preci != -1)	
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
	else
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
	if (ft_strcmp(lst->indic, "-") == 0)
		lst->larg = ft_strjoin("-", lst->larg);
	lst->str = ft_strlowcase(ft_strreplace(lst->str,
				lst->str, ft_largeur(ft_atoi(lst->larg), lst->str, lst)));
}
