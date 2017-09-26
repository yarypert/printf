/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <aancel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 02:49:45 by aancel            #+#    #+#             */
/*   Updated: 2017/09/26 16:05:28 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_err(int error)
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
	lst->indic = NULL;
	lst->larg = NULL;
	lst->larg_c = '!';
	lst->larg_nbr = 0;
	lst->preci = 0;
	lst->mode_h = 0;
	lst->mode_l = 0;
	lst->mode_j = 0;
	lst->mode_z = 0;
}

char	*set_indic_val(char *str, int *i)
{
	int tmp;

	tmp = *i;
	while (str[*i] == '-' || str[*i] == '+' || str[*i] == ' ' || str[*i] == '#')
		*i = *i + 1; 
	return (ft_strsub(str, tmp, *i - tmp));
}

char	*set_larg_val(char *str, int *i)
{
	int tmp;

	tmp = *i;
	while (ft_isdigit(str[*i]) || str[*i] == '*')
		*i = *i + 1;
	return (ft_strsub(str, tmp, *i - tmp));
}

int		set_preci_val(char *str, int *i)
{
	int save;

	save = 0;
	if (str[*i] == '.')
	{
		*i = *i + 1;
		save = ft_atoi(&str[*i]);
		while (ft_isdigit(str[*i]))
			*i = *i + 1;
	}
	else
		return(-1);
	return (save);
}

void	set_op(char c, t_lst *lst)
{
	lst->mode_h += (c == 'h');
	lst->mode_l += (c == 'l');
	lst->mode_j += (c == 'j');
	lst->mode_z += (c == 'z');
}

void	set_mode_val(t_lst *lst, int *i)
{
	int len;

	len = ft_strlen(lst->str);
	while (len - *i - 1 > 0)
	{
		set_op(lst->str[*i], lst);
		*i = *i + 1;
	}
}

void	dcp_larg_val(char *str, t_lst *lst)
{
	int i;

	i = 0;
	if (str[i] == '0' || str[i] == '*')
		lst->larg_c = str[i++];
	lst->larg_nbr = ft_atoi(&str[i]);
}

int		valid_option_flag(t_lst *lst)
{
	int len;
	int i;

	i = 1;
	len = ft_strlen(lst->str);
	init_flag(lst);
	lst->type = lst->str[len - 1];
	lst->indic = set_indic_val(lst->str, &i);
	lst->larg = set_larg_val(lst->str, &i);
	dcp_larg_val(lst->larg, lst);
	lst->preci = set_preci_val(lst->str, &i);
	set_mode_val(lst, &i);
	return (0);
}

void	check_lst(t_lst *lst)
{
	while (lst)
	{
		if (lst->flag == 1)
		{
			if (valid_option_flag(lst) == -1)
				ft_err(1);
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
			printf("\tindic: `%s`\n", lst->indic);
			printf("\tlarg: %s\n", lst->larg);
			printf("\tlarg_c: %c\n", lst->larg_c);
			printf("\tlarg_nbr: %d\n", lst->larg_nbr);
			printf("\tpreci: %d\n", lst->preci);
			printf("\ttype: %c\n", lst->type);

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
   }*/
