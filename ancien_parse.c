/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <aancel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 02:49:45 by aancel            #+#    #+#             */
/*   Updated: 2017/07/27 15:16:47 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		iscc(char c)
{
	return (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' ||
		c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x' ||
		c == 'X' || c == 'c' || c == 'C' || c == '%');
}

t_lst	*make_lst(char *str, t_lst *lst)
{
	t_lst *tmp;

	if (!lst)
	{
		if(!(tmp = (t_lst *)malloc(sizeof(t_lst))))
			return(NULL);
		tmp->str = str;
		tmp->flag = (str[0] == '%' ? 1 : 0);
		tmp->next = NULL;
		tmp->prev = NULL;
	}
	else
	{
		tmp = lst;
		while (lst && lst->next != NULL)
			lst = lst->next;
		if(!(lst->next = (t_lst *)malloc(sizeof(t_lst))))
			return(NULL);
		lst->next->str = str;
		lst->next->flag = (str[0] == '%' ? 1 : 0);
		lst->next->next = NULL;
		lst->next->prev = lst;
	}
	return (tmp);
}

t_lst	*ftp_parsing(char *str)
{
	int i;
	int len;
	t_lst *lst;

	lst = NULL;
	i = 0;
	while (str)
	{
		if (str[i] != '%')
		{
			len = 0;
			while (str[i + len] && str[i + len] != '%')
				len++;
		}
		else
		{
			len = 1;
			while (str[i + len] && !iscc(str[i + len++])) ;
		}
		lst = make_lst(ft_strsub(str, i, len), lst);
		i = i + len;
		if (str[i] == '\0')
			break;
	}
	return (lst);
}
