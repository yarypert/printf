/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 23:18:32 by yarypert          #+#    #+#             */
/*   Updated: 2017/11/23 09:45:52 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*test(t_lst *lst)
{
	char *str;
	int i = 0;
	str = (char *)malloc(sizeof(char) * ft_atoi(lst->larg) + 1);
	if (ft_atoi(lst->larg) == 1)
		lst->larg = ft_strreplace(lst->larg, lst->larg, "0");
	while (i < ft_atoi(lst->larg) - 1)
	{
		str[i] = ' ';
		i++;
	}
	return(str);
}

void	flag_c(t_env *env, t_lst *lst)
{
	lst->argu = ft_ctoa(va_arg(env->args, int));
	lst->str = ft_strreplace(lst->str, lst->str, lst->argu);
	if(ft_strcmp(lst->indic , "-") == 0)
		lst->larg = ft_strjoin("-", lst->larg);
	lst->str = ft_strreplace(lst->str, lst->str, ft_largeur(ft_atoi(lst->larg), lst->str, lst));
	
	if (((ft_strcmp(ft_ctoa(lst->type), "c")) == 0 && (ft_strcmp(lst->argu, "") == 0 || ft_strcmp(lst->argu, "NULL") == 0 || ft_strcmp(lst->argu, "\0") == 0)))
	{
		lst->str = test(lst);
		env->ret++;
	}
}
