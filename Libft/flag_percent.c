/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 00:14:24 by yarypert          #+#    #+#             */
/*   Updated: 2017/10/04 00:15:02 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	flag_percent(t_env *env, t_lst *lst)
{
	if(ft_strcmp(lst->indic, "-") == 0)
		lst->larg = ft_strjoin("-", lst->larg);
	if (ft_strcmp(env->format, "%") == 0)
		lst->str = ft_strreplace(lst->str, lst->str, "");
	else
		lst->str = ft_strreplace(lst->str, lst->str, "%");
	lst->str = ft_largeur(ft_atoi(lst->larg), lst->str, lst);
}
