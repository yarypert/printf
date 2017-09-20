/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 16:00:32 by yarypert          #+#    #+#             */
/*   Updated: 2017/09/20 19:01:16 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	flag_o(t_env *env, t_lst *lst)
{
	if (lst->preci != -1)
	{
		if(lst->mode_l == 1)
			lst->str = ft_strreplace(lst->str, lst->str, precision_int
			(ft_ultoa_base(va_arg(env->args, unsigned long int), 8), lst->preci));
		else if(lst->mode_l == 2 || lst->mode_j == 1)
			lst->str = ft_strreplace(lst->str, lst->str, precision_int
			(ft_ultoa_base(va_arg(env->args, unsigned long long int), 8), lst->preci));
		
		else
			lst->str = ft_strreplace(lst->str, lst->str, precision_int
			(ft_ultoa_base(va_arg(env->args, unsigned int), 8), lst->preci));
	}
	else
	{
		if(lst->mode_l == 1)
			lst->str = ft_strreplace(lst->str, lst->str,
				ft_ultoa_base(va_arg(env->args, unsigned long int), 8));
		else if(lst->mode_l == 2 || lst->mode_j == 1)
			lst->str = ft_strreplace(lst->str, lst->str,
				ft_ultoa_base(va_arg(env->args, unsigned long long int), 8));
		else
		lst->str = ft_strreplace(lst->str, lst->str,
			ft_ultoa_base(va_arg(env->args, unsigned int), 8));
	}
	if(ft_strcmp(lst->indic , "-") == 0)
		lst->larg = ft_strjoin("-", lst->larg);
	lst->str = ft_strlowcase(ft_strreplace(lst->str, lst->str, ft_largeur(ft_atoi(lst->larg), lst->str, lst)));
}

void	flag_bigo(t_env *env, t_lst *lst)
{
	if (lst->preci != -1)
	{
		lst->str = ft_strreplace(lst->str, lst->str, precision_int(ft_ltoa_base
					(va_arg(env->args, long int), 8), lst->preci));
	}
	else
	{
		lst->str = ft_strreplace(lst->str, lst->str, ft_ltoa_base
				(va_arg(env->args, long int), 8));
	}
	if(ft_strcmp(lst->indic , "-") == 0)
		lst->larg = ft_strjoin("-", lst->larg);
	lst->str = ft_strreplace(lst->str, lst->str, ft_largeur(ft_atoi(lst->larg), lst->str, lst));
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
	if(ft_strcmp(lst->indic , "-") == 0)
		lst->larg = ft_strjoin("-", lst->larg);
	lst->str = ft_strreplace(lst->str, lst->str, ft_largeur(ft_atoi(lst->larg), lst->str, lst));
}

void	flag_x(t_env *env, t_lst *lst)
{
	if (lst->preci != -1)
	{
		if(lst->mode_l == 1)
			lst->str = ft_strreplace(lst->str, lst->str, precision_int
			(ft_ultoa_base(va_arg(env->args, unsigned long int), 16), lst->preci));
		else if(lst->mode_l == 2 || lst->mode_j == 1)
			lst->str = ft_strreplace(lst->str, lst->str, precision_int
			(ft_ultoa_base(va_arg(env->args, unsigned long long int), 16), lst->preci));
		else
			lst->str = ft_strreplace(lst->str, lst->str, precision_int
			(ft_ultoa_base(va_arg(env->args, unsigned int), 16), lst->preci));
	}
	else
	{
		if(lst->mode_l == 1)
			lst->str = ft_strreplace(lst->str, lst->str,
				ft_ultoa_base(va_arg(env->args, unsigned long int), 16));
		else if(lst->mode_l == 2 || lst->mode_j == 1)
			lst->str = ft_strreplace(lst->str, lst->str,
				ft_ultoa_base(va_arg(env->args, unsigned long long int), 16));
		else
		lst->str = ft_strreplace(lst->str, lst->str,
			ft_ultoa_base(va_arg(env->args, unsigned int), 16));
	}
	if(ft_strcmp(lst->indic , "-") == 0)
		lst->larg = ft_strjoin("-", lst->larg);
	lst->str = ft_strlowcase(ft_strreplace(lst->str, lst->str, ft_largeur(ft_atoi(lst->larg), lst->str, lst)));
}

void	flag_bigx(t_env *env, t_lst *lst)
{
	flag_x(env, lst);
	lst->str = ft_strreplace(lst->str, lst->str, ft_strupcase(lst->str));
}
