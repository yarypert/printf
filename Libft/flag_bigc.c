/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_bigc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 23:19:38 by yarypert          #+#    #+#             */
/*   Updated: 2017/10/03 23:20:39 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	flag_bigc(t_env *env, t_lst *lst)
{
	lst->str = ft_strreplace(lst->str, lst->str,
			ft_getwchar(va_arg(env->args, wchar_t)));
}
