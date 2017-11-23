/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 12:13:26 by yarypert          #+#    #+#             */
/*   Updated: 2017/11/23 10:37:41 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	if (lst->type == 's')
		flag_s(env, lst);
	if (lst->type == 'p')
		flag_p(env, lst);
	if (lst->type == 'd' || lst->type == 'i')
		flag_d(env, lst);
	if (lst->type == 'D')
		flag_bigd(env, lst);
	if (lst->type == 'o')
		flag_o(env, lst);
	if (lst->type == 'O')
		flag_bigo(env, lst);
	if (lst->type == 'x')
		flag_x(env, lst);
	if (lst->type == 'X')
		flag_bigx(env, lst);
	ft_chooseflag2(env, lst);
}

void	ft_chooseflag2(t_env *env, t_lst *lst)
{
	if (lst->type == 'c')
		flag_c(env, lst);
	if (lst->type == 'C')
		flag_bigc(env, lst);
	if (lst->type == 'b')
		flag_b(env, lst);
	if (lst->type == 'U')
		flag_bigu(env, lst);
	if (lst->type == '%')
		flag_percent(env, lst);
	if (lst->type == 'S')
		ft_putstr("LOL MDR TU LA PAS FAIT PD\n");
	if (lst->type == 'u')
		flag_u(env, lst);
}
