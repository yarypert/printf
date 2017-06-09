/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 03:30:54 by yarypert          #+#    #+#             */
/*   Updated: 2017/06/09 05:06:40 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		process(t_env *env, t_lst *lst)
{
	lst = ftp_parsing(env->format);
	check_lst(lst);
	return (env->ret);
}
