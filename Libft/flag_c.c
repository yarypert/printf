/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 23:18:32 by yarypert          #+#    #+#             */
/*   Updated: 2017/10/03 23:19:28 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	flag_c(t_env *env, t_lst *lst)
{
	lst->str = ft_strreplace(lst->str, lst->str,
			ft_ctoa(va_arg(env->args, int)));
	if(ft_strcmp(lst->indic , "-") == 0)
		lst->larg = ft_strjoin("-", lst->larg);
	lst->str = ft_strreplace(lst->str, lst->str, ft_largeur(ft_atoi(lst->larg), lst->str, lst));

}
