/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_bigx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 23:16:48 by yarypert          #+#    #+#             */
/*   Updated: 2017/10/03 23:17:19 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	flag_bigx(t_env *env, t_lst *lst)
{
	flag_x(env, lst);
	lst->	str = ft_strreplace(lst->str, lst->str, ft_strupcase(lst->str));
}
