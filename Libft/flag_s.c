/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 23:05:37 by yarypert          #+#    #+#             */
/*   Updated: 2017/12/01 01:58:51 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	flag_s(t_env *env, t_lst *lst)
{
	lst->svalue = va_arg(env->args, char*);
	if (lst->svalue == NULL)
		lst->str = ft_strreplace(lst->str, lst->str ,"(null)");
	else
	{
		if (ft_strcmp(lst->svalue, "") == 0)
			lst->str = ft_strreplace(lst->str, lst->str, ft_largeur(ft_atoi(lst->larg), "", lst));
		else
		{
			if (lst->preci != -1)
				flag_s_preci(lst);
			else
				flag_s_nopreci(lst);
			if (ft_strcmp(lst->indic, "-") == 0)
				lst->larg = ft_strjoin("-", lst->larg);
			lst->str = ft_strreplace(lst->str, lst->str, ft_largeur(ft_atoi(lst->larg),
						lst->str, lst));
		}
	}
}

void	flag_s_preci(t_lst *lst)
{
	lst->str = ft_strreplace(lst->str, lst->str,
			precision_string(lst->svalue, lst->preci));
}

void	flag_s_nopreci(t_lst *lst)
{
	lst->str = ft_strreplace(lst->str, lst->str, lst->svalue);
}
