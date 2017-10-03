/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_bigu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 23:14:29 by yarypert          #+#    #+#             */
/*   Updated: 2017/10/03 23:15:20 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	flag_bigu(t_env *env, t_lst *lst)
{
	if (lst->preci != -1)
	{
		lst->str = ft_strreplace(lst->str, lst->str,
				precision_int(ft_ltoa(va_arg(env->args, unsigned int)), lst->preci));
	}
	else
	{
		lst->str = ft_strreplace(lst->str, lst->str,
				ft_ltoa(va_arg(env->args, unsigned int)));
	}
	if (ft_strcmp(lst->indic, "-") == 0)
		lst->larg = ft_strjoin("-", lst->larg);
	lst->str = ft_strreplace(lst->str, lst->str,
			ft_largeur(ft_atoi(lst->larg), lst->str, lst));
}
