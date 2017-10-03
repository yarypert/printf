/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_bigo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 23:13:29 by yarypert          #+#    #+#             */
/*   Updated: 2017/10/03 23:14:12 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	flag_bigo(t_env *env, t_lst *lst)
{
	if (lst->preci !=	 -1)
	{
		lst->str = ft_strreplace(lst->str, lst->str,
				precision_int(ft_ltoa_base(va_arg(env->args, long int), 8), lst->preci));
	}
	else
	{
		lst->str = ft_strreplace(lst->str, lst->str,
				ft_ltoa_base(va_arg(env->args, long int), 8));
	}
	if (ft_strcmp(lst->indic, "-") == 0)
		lst->larg = ft_strjoin("-", lst->larg);
	lst->str = ft_strreplace(lst->str,
			lst->str, ft_largeur(ft_atoi(lst->larg), lst->str, lst));
}
