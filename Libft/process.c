/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 03:30:54 by yarypert          #+#    #+#             */
/*   Updated: 2017/09/06 18:51:19 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		process(t_env *env, t_lst *lst)
{
	lst = ftp_parsing(env->format);
	check_lst(lst);
	aff_valid_lst(lst);
	ft_dispatcher(env, lst);
	print_list(env, lst);
	return (env->ret);
}
