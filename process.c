/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 03:30:54 by yarypert          #+#    #+#             */
/*   Updated: 2017/07/27 17:26:38 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		process(t_env *env, t_lst *lst)
{
	lst = ftp_parsing(env->format);
	ft_dispatcher(env, lst);
	print_list(env, lst);
	return (env->ret);
}
