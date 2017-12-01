/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 23:07:43 by yarypert          #+#    #+#             */
/*   Updated: 2017/12/01 12:09:49 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	flag_d(t_env *env, t_lst *lst)
{
	lst->dvalue = va_arg(env->args, long long int);
	if (lst->preci != -1)
		flag_d_preci(lst);
	else
		flag_d_nopreci(lst);
	if (ft_strchr(lst->indic, '-') != 0)
	{
		lst->larg_c = 0;
		lst->larg = ft_strjoin("-", lst->larg);
	}
		lst->str = ft_strreplace(lst->str, lst->str,
			ft_largeur(ft_atoi(lst->larg), lst->str, lst));
	if (ft_strchr(lst->indic, '+') != 0 && ft_strchr(lst->str, '-') == 0)
		lst->str = ft_strjoin("+", lst->str);
	else if(ft_strchr(lst->indic, '+') == 0 && ft_strchr(lst->str, '-') == 0 && 
			ft_strchr(lst->indic, ' ') != 0)
		lst->str = ft_strjoin(" ", lst->str);
}

void	flag_d_preci(t_lst *lst)
{
	if (lst->mode_l == 1)
		lst->str = ft_strreplace(lst->str, lst->str,
				precision_int(ft_ltoa((long int)lst->dvalue), lst->preci));
	else if (lst->mode_l == 2 || lst->mode_j == 1)
		lst->str = ft_strreplace(lst->str, lst->str,
				precision_int(ft_lltoa((long long int)lst->dvalue), lst->preci));
	else if (lst->mode_z == 1)
		lst->str = ft_strreplace(lst->str, lst->str,
				precision_int(ft_ultoa((unsigned long int)lst->dvalue), lst->preci));
	else
		lst->str = ft_strreplace(lst->str, lst->str,
				precision_int(ft_itoa((int)lst->dvalue), lst->preci));
}

void	flag_d_nopreci(t_lst *lst)
{
	if (lst->mode_l == 1)
		lst->str = ft_strreplace(lst->str, lst->str,
				ft_ltoa((long int)lst->dvalue));
	else if (lst->mode_l == 2 || lst->mode_j == 1)
		lst->str = ft_strreplace(lst->str, lst->str,
				ft_lltoa((long long int)lst->dvalue));
	else if (lst->mode_z == 1)
		lst->str = ft_strreplace(lst->str, lst->str,
				ft_ultoa((unsigned long int)lst->dvalue));
	else
		lst->str = ft_strreplace(lst->str, lst->str,
				ft_itoa((int)lst->dvalue));
}
