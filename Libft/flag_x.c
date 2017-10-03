/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 23:15:30 by yarypert          #+#    #+#             */
/*   Updated: 2017/10/03 23:16:35 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	flag_x(t_env *env, t_lst *lst)
{
	int i;
	i = 0;
	if (lst->preci	 != -1)
	{
		if (lst->mode_l == 1)
			lst->str = ft_strreplace(lst->str, lst->str,
					precision_int(ft_ultoa_base(va_arg(env->args, unsigned long int), 16),
						lst->preci));
		else if (lst->mode_l == 2 || lst->mode_j == 1)
			lst->str = ft_strreplace(lst->str, lst->str,
					precision_int(ft_ultoa_base(va_arg(env->args, unsigned long long int), 16),
						lst->preci));
		else
			lst->str = ft_strreplace(lst->str, lst->str,
					precision_int(ft_ultoa_base(va_arg(env->args, unsigned int), 16),
						lst->preci));
	}
	else
	{
	if (lst->mode_l == 1)
		lst->str = ft_strreplace(lst->str, lst->str,
				ft_ultoa_base(va_arg(env->args, unsigned long int), 16));
	else if (lst->mode_l == 2 || lst->mode_j == 1)
		lst->str = ft_strreplace(lst->str, lst->str,
				ft_ultoa_base(va_arg(env->args, unsigned long long int), 16));
	else
		lst->str = ft_strreplace(lst->str, lst->str,
				ft_ultoa_base(va_arg(env->args, unsigned int), 16));
	}
	if (ft_strcmp(lst->indic, "#") == 0)
		i = 2;
	if (ft_strcmp(lst->indic, "-") == 0)
		lst->larg = ft_strjoin("-", lst->larg);
	lst->str = ft_strlowcase(ft_strreplace(lst->str,
				lst->str, ft_largeur(ft_atoi(lst->larg) - i, lst->str, lst)));
	if (i == 2)
		lst->str = ft_strjoin("0x", lst->str);
}

void	flag_x2(	t_env *env, t_lst *lst)
{

}
