/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_bigd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 23:08:43 by yarypert          #+#    #+#             */
/*   Updated: 2017/10/04 01:39:38 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	flag_bigd(t_env *env, t_lst *lst)
{
	if (lst->preci != -1)
	{
		lst->str = ft_strreplace(lst->str, lst->str,
				precision_int(ft_ltoa(va_arg(env->args, long int)), lst->preci));
	}
	else
	{
		lst->str = ft_strreplace(lst->str, lst->str,
				ft_ltoa(va_arg(env->args, long int)));
	}
	if (ft_strcmp(lst->indic, "-") == 0)
		lst->larg = ft_strjoin("-", lst->larg);
	lst->str = ft_strreplace(lst->str, lst->str,
			ft_largeur(ft_atoi(lst->larg), lst->str, lst));
}
