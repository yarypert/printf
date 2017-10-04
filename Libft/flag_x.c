/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 23:15:30 by yarypert          #+#    #+#             */
/*   Updated: 2017/10/04 11:51:24 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	flag_x(t_env *env, t_lst *lst)
{
	lst->xvalue = va_arg(env->args, unsigned long long int);

	if (lst->preci != -1)
		flag_x_preci(lst);
	else
		flag_x_nopreci(lst);
	if (ft_strchr(lst->indic, '-') != 0)
	{
		lst->larg_c = 0;
		lst->larg = ft_strjoin("-", lst->larg);
	}
	if (lst->xvalue == 0 && lst->preci == -1)
		lst->str = ft_strreplace(lst->str, lst->str, "0");
	else if ((lst->preci != -1) && lst->xvalue == 0)
		lst->str = ft_strreplace(lst->str, lst->str, "");
	lst->str = ft_strlowcase(ft_strreplace(lst->str,
		lst->str, ft_largeur(ft_atoi(lst->larg), lst->str, lst)));

}

void	flag_x_preci(t_lst *lst)
{
	if (lst->mode_l == 1)
	{
		if (ft_strchr(lst->indic, '#') != 0)
		{
			lst->str = ft_strjoin("0x", ft_strreplace(lst->str, lst->str, precision_int
					(ft_ultoa_base((unsigned long int)lst->xvalue, 16),
					 lst->preci)));
		}
		else
		{
			lst->str = ft_strreplace(lst->str, lst->str, precision_int
					(ft_ultoa_base((unsigned long int)lst->xvalue, 16),
					 lst->preci));
		}
	}
	else if (lst->mode_l == 2 || lst->mode_j == 1)
	{
		if (ft_strchr(lst->indic, '#') != 0)
		{
			lst->str = ft_strjoin("0x", ft_strreplace(lst->str, lst->str, precision_int
					(ft_ultoa_base((unsigned long long int)lst->xvalue, 16),
					 lst->preci)));
		}
		else
		{
			lst->str = ft_strreplace(lst->str, lst->str, precision_int
					(ft_ultoa_base((unsigned long long int)lst->xvalue, 16),
					 lst->preci));
		}
	}
	else
		flag_x_precisharp(lst);
}

void	flag_x_precisharp(t_lst *lst)
{
	if (ft_strchr(lst->indic, '#') != 0)
		lst->str = ft_strjoin("0x", ft_strreplace(lst->str, lst->str,
					precision_int(ft_ultoa_base((unsigned int)lst->xvalue,
							16), lst->preci)));
	else
		lst->str = ft_strreplace(lst->str, lst->str,
				precision_int(ft_ultoa_base((unsigned int)lst->xvalue,
						16), lst->preci));
}

void	flag_x_nopreci(t_lst *lst)
{
	if (lst->mode_l == 1)
	{
		if (ft_strchr(lst->indic, '#') != 0)
		{
			lst->str = ft_strjoin("0x", ft_strreplace(lst->str, lst->str,
					ft_ultoa_base((unsigned long int)lst->xvalue, 16)));
		}
		else
		{
			lst->str = ft_strreplace(lst->str, lst->str,
					ft_ultoa_base((unsigned long int)lst->xvalue, 16));
		}
	}
	else if (lst->mode_l == 2 || lst->mode_j == 1)
	{
		if (ft_strchr(lst->indic, '#') != 0)
		{
			lst->str = ft_strjoin("0x", ft_strreplace(lst->str, lst->str,
					ft_ultoa_base((unsigned long long int)lst->xvalue, 16)));
		}
		else
		{
			lst->str = ft_strreplace(lst->str, lst->str,
					ft_ultoa_base((unsigned long long int)lst->xvalue, 16));
		}
	}
	else
		flag_x_noprecisharp(lst);
}

void	flag_x_noprecisharp(t_lst *lst)
{
	if (ft_strchr(lst->indic, '#') != 0)
		lst->str = ft_strjoin("0x", ft_strreplace(lst->str, lst->str,
					ft_ultoa_base((unsigned int)lst->xvalue, 16)));
	else
		lst->str = ft_strreplace(lst->str, lst->str,
				ft_ultoa_base((unsigned int)lst->xvalue, 16));
}
