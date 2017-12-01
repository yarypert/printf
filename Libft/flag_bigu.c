/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_bigu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 23:14:29 by yarypert          #+#    #+#             */
/*   Updated: 2017/12/01 07:39:01 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	flag_bigu(t_env *env, t_lst *lst)
{
	lst->uvalue = va_arg(env->args, unsigned long int);
	if (lst->preci != -1)
		flag_bigu_preci(lst);
	else
		flag_bigu_nopreci(lst);
	if (ft_strcmp(lst->indic, "-") == 0)
		lst->larg = ft_strjoin("-", lst->larg);
	lst->str = ft_strreplace(lst->str, lst->str,
			ft_largeur(ft_atoi(lst->larg), lst->str, lst));
}

void	flag_bigu_preci(t_lst *lst)
{
	lst->str = ft_strreplace(lst->str, lst->str,
			precision_int(ft_ultoa(lst->uvalue), lst->preci));
}

void	flag_bigu_nopreci(t_lst *lst)
{
		lst->str = ft_strreplace(lst->str, lst->str, ft_ultoa(lst->uvalue));
}
