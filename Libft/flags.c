/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 16:00:28 by yarypert          #+#    #+#             */
/*   Updated: 2017/09/06 15:01:37 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	flag_s(t_env *env, t_lst *lst)
{
	if(lst->preci != -1)
	{
		lst->str = ft_strreplace(lst->str, lst->str, precision_string
				(va_arg(env->args,char*), lst->preci));
	}
	else
	{
		lst->str = ft_strreplace(lst->str, lst->str,
				va_arg(env->args, char*));
	}
	if(ft_strcmp(lst->indic , "-") == 0)
		lst->larg = ft_strjoin("-", lst->larg);
	lst->str = ft_strreplace(lst->str, lst->str, ft_largeur(ft_atoi(lst->larg), lst->str, lst));
}

void	flag_bigs(t_env *env, t_lst *lst)
{
	(void)env;
	(void)lst;
}

void	flag_p(t_env *env, t_lst *lst)
{
	lst->str = ft_strreplace(lst->str, lst->str, ft_putpp(va_arg(env->args,void *)));
}

void	flag_d(t_env *env, t_lst *lst)
{
	if(lst->preci != -1)
	{
		if(lst->mode_l == 1)
			lst->str = ft_strreplace(lst->str, lst->str, precision_int
				(ft_ltoa(va_arg(env->args,long int)), lst->preci));
		else if(lst->mode_l == 2)
			lst->str = ft_strreplace(lst->str, lst->str, precision_int
				(ft_ltoa(va_arg(env->args,long long int)), lst->preci));
		else
			lst->str = ft_strreplace(lst->str, lst->str, precision_int
				(ft_itoa(va_arg(env->args,int)), lst->preci));
	}
	else
	{
		if(lst->mode_l == 1)
			lst->str = ft_strreplace(lst->str, lst->str,
				ft_itoa(va_arg(env->args,long int)));
		else if(lst->mode_l == 2)
			lst->str = ft_strreplace(lst->str, lst->str,
				ft_ltoa(va_arg(env->args,long long int)));
		else
			lst->str = ft_strreplace(lst->str, lst->str,
				ft_ltoa(va_arg(env->args,int)));
	}
	if(ft_strcmp(lst->indic , "-") == 0)
		lst->larg = ft_strjoin("-", lst->larg);
	lst->str = ft_strreplace(lst->str, lst->str, ft_largeur(ft_atoi(lst->larg), lst->str, lst));
}

void	flag_bigd(t_env *env, t_lst *lst)
{
	if(lst->preci != -1)
	{
		lst->str = ft_strreplace(lst->str, lst->str, precision_int
				(ft_ltoa(va_arg(env->args,long int)),lst->preci));
	}
	else
	{
		lst->str = ft_strreplace(lst->str, lst->str,
				ft_ltoa(va_arg(env->args,long int)));
	}
	if(ft_strcmp(lst->indic , "-") == 0)
		lst->larg = ft_strjoin("-", lst->larg);
	lst->str = ft_strreplace(lst->str, lst->str, ft_largeur(ft_atoi(lst->larg), lst->str, lst));
}
