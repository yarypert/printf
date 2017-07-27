/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printflags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 11:51:53 by yarypert          #+#    #+#             */
/*   Updated: 2017/07/27 16:50:02 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	print_list(t_env *env, t_lst *lst)
{
	while (lst)
	{
		// if (!lst->flag)
		// {
			env->ret = env->ret + write(1, lst->str, ft_strlen(lst->str));
		// }
		if (lst->next != NULL)
			lst = lst->next;
		else
			break ;
	}
	// while (lst)
	// {
	// 	ft_putstr(L_VERT);
	// 	ft_putstr(lst->str);
	// 	ft_putendl(FIN);
	// 	if (lst->prev != NULL)
	// 		lst = lst->prev;
	// 	else
	// 		break ;
	// }
}
