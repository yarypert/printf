/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 23:06:58 by yarypert          #+#    #+#             */
/*   Updated: 2017/10/03 23:07:36 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	flag_p(t_env *env, t_lst *lst)
{
		lst->str = ft_strreplace(lst->str, lst->str,
							ft_putpp(va_arg(env->args, void *)));
}
