/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_bigo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 23:13:29 by yarypert          #+#    #+#             */
/*   Updated: 2017/12/01 05:42:39 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	flag_bigo(t_env *env, t_lst *lst)
{
	{
		lst->xvalue = va_arg(env->args, unsigned long long int);
		if (lst->preci == 0 && lst->xvalue == 0 && (ft_strchr(lst->indic, '#') != 0))
			lst->str = ft_strreplace(lst->str,
					lst->str, ft_largeur(ft_atoi(lst->larg), "0", lst));
		else if(lst->preci == 0 && lst->xvalue == 0)
			lst->str = ft_strreplace(lst->str,
					lst->str, ft_largeur(ft_atoi(lst->larg), "", lst));
		else
		{
			if (ft_atoi(lst->larg) >= 2 && ft_strchr(lst->indic, '#') != 0 &&
					ft_strchr(lst->indic, '-') == 0 && lst->larg_c == '0')
				lst->larg = ft_itoa(ft_atoi(lst->larg) - 1);
			if (lst->preci != -1)
				flag_bigo_preci(lst);
			else
				flag_bigo_nopreci(lst);
			if (ft_strchr(lst->indic, '-') != 0)
			{
				lst->larg_c = 0;
				lst->larg = ft_strjoin("-", lst->larg);
			}
			if (ft_strchr(lst->indic, '#') != 0 && lst->xvalue != 0 &&
					lst->larg_c != '0')
				lst->str = ft_strjoin("0", lst->str);
			lst->str = ft_strreplace(lst->str,
					lst->str, ft_largeur(ft_atoi(lst->larg), lst->str, lst));
			if (ft_strchr(lst->indic, '#') != 0 && lst->xvalue != 0 &&
					lst->larg_c == '0')
			{
				lst->str = ft_strjoin("0", lst->str);
			}
			lst->str = ft_strreplace(lst->str,
					lst->str, ft_largeur(ft_atoi(lst->larg), lst->str, lst));
			lst->str = ft_strlowcase(lst->str);
		}
	}
}

void	flag_bigo_preci(t_lst *lst)
{
	lst->str = ft_strreplace(lst->str, lst->str, precision_int
			(ft_ultoa_base((unsigned long int)lst->xvalue, 8), lst->preci));
}

void	flag_bigo_nopreci(t_lst *lst)
{
	lst->str = ft_strreplace(lst->str, lst->str,
			ft_ultoa_base((unsigned long int)lst->xvalue, 8));
}
