/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <aancel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 02:49:45 by aancel            #+#    #+#             */
/*   Updated: 2017/06/10 18:45:31 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_error(int error)
{
	if (error == 1)
		ft_putendl(L_ROUGE "invalid flag" FIN);
	exit (-1);
}

int		iscc(char c)
{
	return (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' ||
		c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x' ||
		c == 'X' || c == 'c' || c == 'C' || c == 'b' || c == '%');
}

t_lst	*make_lst(char *str, t_lst *lst)
{
	t_lst *tmp;

	if (!lst)
	{
		tmp = (t_lst *)malloc(sizeof(t_lst));
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
		lst->next = (t_lst *)malloc(sizeof(t_lst));
		lst->next->str = str;
		lst->next->flag = (str[0] == '%' ? 1 : 0);
		lst->next->next = NULL;
		lst->next->prev = lst;
	}
	return (tmp);
}

void	init_flag(t_lst *lst)
{
	lst->mode_h = 0;
	lst->mode_l = 0;
	lst->mode_j = 0;
	lst->mode_z = 0;
	lst->mode_zero = 0;
	lst->opt_more = 0;
	lst->opt_less = 0;
	lst->opt_nbr = -1;
	lst->opt_hash = 0;
	lst->opt_spc = 0;

}

void	set_op(char c, t_lst *lst)
{
	lst->mode_h += (c == 'h');
	lst->mode_l += (c == 'l');
	lst->mode_j = (c == 'j');
	lst->mode_z = (c == 'z');
	lst->opt_more = (c == '+');
	lst->opt_less = (c == '-');
	lst->opt_hash = (c == '#');
	lst->opt_spc = (c == ' ');
}

int		isop(char c)
{
	return (c == 'h' || c == 'l' || c == 'j' || c == 'z' || c == '+' ||
		c == '-' || c == '#' || c == ' ');
}

int		check_flag(char *flag2, t_lst *lst)
{
	int i;

	i = 0;
	if (ft_isdigit(flag2[i]))
	{
		lst->opt_nbr = ft_atoi(&flag2[i]);
		while(ft_isdigit(flag2[i++])) ;
	}
	else if (isop(flag2[i]))
	{
		set_op(flag2[i], lst);
		i++;
	}
	else
		return (-1);
	return (0);
}



int		valid_option_flag(t_lst *lst)
{
	int len;
	char *flag2;

	len = ft_strlen(lst->str);
	flag2 = ft_strsub(lst->str, 1, len - 2);
	init_flag(lst);
	return (check_flag(flag2, lst));
}

void	check_lst(t_lst *lst)
{
	while (lst)
	{
		if (lst->flag)
		{
			if (valid_option_flag(lst) == -1)
				ft_error(1);
		}
		if (lst->next != NULL)
			lst = lst->next;
		else
			break ;
	}
}

// void	check_lst(t_lst *lst)
// {
// 	while (lst)
// 	{
// 		ft_putstr(L_ROUGE);
// 		ft_putstr(lst->str);
// 		ft_putendl(FIN);
// 		if (lst->next != NULL)
// 			lst = lst->next;
// 		else
// 			break ;
// 	}
// 	while (lst)
// 	{
// 		ft_putstr(L_VERT);
// 		ft_putstr(lst->str);
// 		ft_putendl(FIN);
// 		if (lst->prev != NULL)
// 			lst = lst->prev;
// 		else
// 			break ;
// 	}
// }

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

int		main(int argc, char **argv)
{
	t_lst *lst;

	argc += 0;
	lst = NULL;
	lst = ftp_parsing(argv[1]);
	check_lst(lst);
	return (0);
}
