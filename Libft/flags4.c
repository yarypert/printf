/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 15:24:10 by yarypert          #+#    #+#             */
/*   Updated: 2017/09/27 12:45:37 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	flag_percent(t_env *env, t_lst *lst)
{
	if(ft_strcmp(lst->indic, "-") == 0)
		lst->larg = ft_strjoin("-", lst->larg);
	if (ft_strcmp(env->format, "%") == 0)
		lst->str = ft_strreplace(lst->str, lst->str, "");
	else
		lst->str = ft_strreplace(lst->str, lst->str, "%");
	lst->str = ft_largeur(ft_atoi(lst->larg), lst->str, lst);
}

void	flag_bigs(t_env *env, t_lst *lst)
{
	(void)env;
	(void)lst;
}

void	flag_u(t_env *env, t_lst *lst)
{
	if (lst->preci != -1)
	{
		if (lst->mode_l == 1)
			lst->str = ft_strreplace(lst->str, lst->str,
					precision_int(ft_ultoa_base(va_arg(env->args, unsigned long int), 10),
						lst->preci));
		else if (lst->mode_l == 2 || lst->mode_j == 1)
			lst->str = ft_strreplace(lst->str, lst->str,
					precision_int(ft_ultoa_base(va_arg(env->args, unsigned long long int), 10),
						lst->preci));
		else
			lst->str = ft_strreplace(lst->str, lst->str,
					precision_int(ft_ultoa_base(va_arg(env->args, unsigned int), 10),
						lst->preci));
	}
	else
	{
		flag_u2(env, lst);
	}
	if (ft_strcmp(lst->indic, "-") == 0)
		lst->larg = ft_strjoin("-", lst->larg);
	lst->str = ft_strlowcase(ft_strreplace(lst->str,
				lst->str, ft_largeur(ft_atoi(lst->larg), lst->str, lst)));
}

void	flag_u2(t_env *env, t_lst *lst)
{	
	if (lst->mode_l == 1)
		lst->str = ft_strreplace(lst->str, lst->str,
				ft_ultoa_base(va_arg(env->args, unsigned long int), 10));
	else if (lst->mode_l == 2 || lst->mode_j == 1)
		lst->str = ft_strreplace(lst->str, lst->str,
				ft_ultoa_base(va_arg(env->args, unsigned long long int), 10));
	else
		lst->str = ft_strreplace(lst->str, lst->str,
				ft_ultoa_base(va_arg(env->args, unsigned int), 10));
}
