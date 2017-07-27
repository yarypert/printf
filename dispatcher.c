/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 12:13:26 by yarypert          #+#    #+#             */
/*   Updated: 2017/07/27 16:56:19 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_dispatcher(t_env *env, t_lst *lst)
{
	while (lst)
	{
		if (lst->flag)
			ft_chooseflag(env, lst);
		if (lst->next != NULL)
			lst = lst->next;
		else
			break ;
	}
}

void	ft_chooseflag(t_env *env, t_lst *lst)
{
	if(lst->str[ft_strlen(lst->str) - 1] == 'd' || lst->str[ft_strlen(lst->str) - 1] == 'i')
		flag_d(env, lst);
	if(lst->str[ft_strlen(lst->str) - 1] == 'c')
		flag_c(env, lst);
	if(lst->str[ft_strlen(lst->str) - 1] == 's')
		flag_s(env, lst);
	if(lst->str[ft_strlen(lst->str) - 1] == 'C')
		flag_bigc(env, lst);
	if(lst->str[ft_strlen(lst->str) - 1] == 'b')
		flag_b(env, lst);
	if(lst->str[ft_strlen(lst->str) - 1] == 'o')
		flag_o(env, lst);
	if(lst->str[ft_strlen(lst->str) - 1] == 'x')
		flag_x(env, lst);
}
