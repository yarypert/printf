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
//	lst->str = ft_strreplace(lst->str, lst->str, ft_largeur(ft_atoi(lst->larg), va_arg(env->args, char*)));
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
		lst->str = ft_strreplace(lst->str, lst->str, precision_int
				(ft_itoa(va_arg(env->args,int)), lst->preci));
	}
	else
	{
		lst->str = ft_strreplace(lst->str, lst->str,
				ft_itoa(va_arg(env->args,int)));
	}
//	lst->str = ft_strreplace(lst->str, lst->str, ft_largeur(ft_atoi(lst->larg), ft_itoa(va_arg(env->args,long))));
}

void	flag_bigd(t_env *env, t_lst *lst)
{
	if(lst->preci != -1)
	{
		lst->str = ft_strreplace(lst->str, lst->str, precision_int
				(ft_ltoa(va_arg(env->args,long)),lst->preci));
	}
	else
	{
		lst->str = ft_strreplace(lst->str, lst->str,
				ft_ltoa(va_arg(env->args,long)));
	}
//	lst->str = ft_strreplace(lst->str, lst->str, ft_largeur(ft_atoi(lst->larg), ft_ltoa(va_arg(env->args,long))));
}
