/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 23:15:30 by yarypert          #+#    #+#             */
/*   Updated: 2017/11/23 05:22:30 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	flag_x(t_env *env, t_lst *lst)
{
	if(lst->preci == 0 && lst->xvalue == 0)
		lst->str = ft_strreplace(lst->str,
				lst->str, ft_largeur(ft_atoi(lst->larg), "", lst));
	else
	{
		lst->xvalue = va_arg(env->args, unsigned long long int);
		if (ft_atoi(lst->larg) >= 2 && ft_strchr(lst->indic, '#') != 0 &&
				ft_strchr(lst->indic, '-') == 0 && lst->larg_c == '0')
			lst->larg = ft_itoa(ft_atoi(lst->larg) - 2);
		if (lst->preci != -1)
			flag_x_preci(lst);
		else
			flag_x_nopreci(lst);
		if (ft_strchr(lst->indic, '-') != 0)
		{
			lst->larg_c = 0;
			lst->larg = ft_strjoin("-", lst->larg);
		}
		if (ft_strchr(lst->indic, '#') != 0 && lst->xvalue != 0 &&
				lst->larg_c != '0')
			lst->str = ft_strjoin("0x", lst->str);
		lst->str = ft_strreplace(lst->str,
				lst->str, ft_largeur(ft_atoi(lst->larg), lst->str, lst));
		if (ft_strchr(lst->indic, '#') != 0 && lst->xvalue != 0 &&
				lst->larg_c == '0')
		{
			lst->str = ft_strjoin("0x", lst->str);
		}
		lst->str = ft_strreplace(lst->str,
				lst->str, ft_largeur(ft_atoi(lst->larg), lst->str, lst));
		lst->str = ft_strlowcase(lst->str);
	}
}

void	flag_x_preci(t_lst *lst)
{
	if (lst->mode_l == 1)
	{
		lst->str = ft_strreplace(lst->str, lst->str, precision_int
				(ft_ultoa_base((unsigned long int)lst->xvalue, 16),
				 lst->preci));
	}
	else if (lst->mode_l == 2 || lst->mode_j == 1)
	{
		lst->str = ft_strreplace(lst->str, lst->str, precision_int
				(ft_ultoa_base((unsigned long long int)lst->xvalue, 16),
				 lst->preci));
	}
	else
	{
		lst->str = ft_strreplace(lst->str, lst->str,
				precision_int(ft_ultoa_base((unsigned int)lst->xvalue,
						16), lst->preci));
	}
}

void	flag_x_nopreci(t_lst *lst)
{
	if (lst->mode_l == 1)
	{
		lst->str = ft_strreplace(lst->str, lst->str,
				ft_ultoa_base((unsigned long int)lst->xvalue, 16));
	}
	else if (lst->mode_l == 2 || lst->mode_j == 1)
	{
		lst->str = ft_strreplace(lst->str, lst->str,
				ft_ultoa_base((unsigned long long int)lst->xvalue, 16));
	}
	else
		lst->str = ft_strreplace(lst->str, lst->str,
				ft_ultoa_base((unsigned int)lst->xvalue, 16));
}
