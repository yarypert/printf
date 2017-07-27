/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <aancel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 02:49:45 by aancel            #+#    #+#             */
/*   Updated: 2017/07/27 17:37:44 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_cerror(int error)
{
	if (error == 1)
		ft_putendl(L_ROUGE "invalid flag" FIN);
	exit(-1);
}

int		iscc(char c)
{
	return (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' ||
		c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x' ||
		c == 'X' || c == 'c' || c == 'C' || c == 'b' || c == '%');
}

int		set_val_flag(char c)
{
	if (c == '%')
		return (1);
	else if (c == '{')
		return (2);
	else
		return (0);
}

t_lst	*make_lst(char *str, t_lst *lst)
{
	t_lst *tmp;

	if (!lst)
	{
		tmp = (t_lst *)malloc(sizeof(t_lst));
		tmp->str = str;
		tmp->flag = set_val_flag(str[0]);
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
		lst->next->flag = set_val_flag(str[0]);
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
	lst->mode_j = (c == 'j' ? 1 : lst->mode_j);
	lst->mode_z = (c == 'z' ? 1 : lst->mode_z);
	lst->opt_more = (c == '+' ? 1 : lst->opt_more);
	lst->opt_less = (c == '-' ? 1 : lst->opt_less);
	lst->opt_hash = (c == '#' ? 1 : lst->opt_hash);
	lst->opt_spc = (c == ' ' ? 1 : lst->opt_spc);
}

int		isop(char c)
{
	return (c == 'h' || c == 'l' || c == 'j' || c == 'z' || c == '+' ||
		c == '-' || c == '#' || c == ' ');
}

float	ft_ftof(char *str, int *i)
{
	int nbr1;
	float nbr2;

	nbr1 = ft_atoi(&str[*i]);
	while (ft_isdigit(str[*i]))
		*i = *i + 1;
	*i = *i + 1;
	nbr2 = (float)ft_atoi(&str[*i]);
	while (ft_isdigit(str[*i]))
		*i = *i + 1;
	while(nbr2 > 1)
		nbr2 /= 10;
	return (nbr1 + nbr2);
}

int		check_flag(char *flag2, t_lst *lst)
{
	int i;

	i = 0;
	while (flag2[i])
	{
		if (ft_isdigit(flag2[i]) || flag2[i] == '.')
		{
			lst->opt_nbr = ft_ftof(flag2, &i);
		}
		else if (isop(flag2[i]))
		{
			set_op(flag2[i], lst);
			i++;
		}
		else
			return (-1);
	}
	return (0);
}

int		valid_option_flag(t_lst *lst)
{
	int len;
	char *flag2;

	len = ft_strlen(lst->str);
	flag2 = ft_strsub(lst->str, 1, len - 2);
	init_flag(lst);
	if (len <= 2)
		return (0);
	else
		return (check_flag(flag2, lst));
}

void	check_lst(t_lst *lst)
{
	while (lst)
	{
		if (lst->flag == 1)
		{
			if (valid_option_flag(lst) == -1)
				ft_cerror(1);
		}
		if (lst->next != NULL)
			lst = lst->next;
		else
			break ;
	}
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
		if (str[i] == '%')
		{
			len = 1;
			while (str[i + len] && !iscc(str[i + len++])) ;
		}
		else if (str[i] == '{')
		{
			len = 1;
			while (str[i + len] && str[i + len++] != '}') ;
		}
		else
		{
			len = 0;
			while (str[i + len] && str[i + len] != '%' && str[i + len] != '{')
				len++;
		}
		lst = make_lst(ft_strsub(str, i, len), lst);
		i = i + len;
		if (str[i] == '\0')
			break;
	}
	return (lst);
}

void	aff_valid_lst(t_lst *lst)
{
	while (lst)
	{
		if (lst->flag == 1)
		{
			printf("flag: %s\n", lst->str);
			printf("\tmode_h: %d\n", lst->mode_h);
			printf("\tmode_l: %d\n", lst->mode_l);
			printf("\tmode_j: %d\n", lst->mode_j);
			printf("\tmode_z: %d\n", lst->mode_z);
			printf("\topt_more: %d\n", lst->opt_more);
			printf("\topt_less: %d\n", lst->opt_less);
			printf("\topt_nbr: %f\n", lst->opt_nbr);
			printf("\topt_hash: %d\n", lst->opt_hash);
			printf("\topt_spc: %d\n", lst->opt_spc);
			printf("---------\n\n");
		}
		else if (lst->flag == 2)
		{
			printf("color: %s\n", lst->str);
			printf("---------\n\n");
		}
		else
		{
			printf("str : %s\n", lst->str);
			printf("---------\n\n");
		}
		if (lst->next != NULL)
			lst = lst->next;
		else
			break ;
	}
}
/*
int		main(int argc, char **argv)
{
	t_lst *lst;

	argc += 0;
	lst = NULL;
	lst = ftp_parsing(argv[1]);
	check_lst(lst);
	aff_valid_lst(lst);
	return (0);
}
*/
