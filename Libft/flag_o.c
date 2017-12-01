#include "libft.h"

void	flag_o(t_env *env, t_lst *lst)
{
	lst->xvalue = va_arg(env->args, unsigned long long int);
	if (lst->preci == 0 && lst->xvalue == 0 && (ft_strchr(lst->indic, '#') != 0))
		lst->str = ft_strreplace(lst->str,
				lst->str, ft_largeur(ft_atoi(lst->larg), "0", lst));
	else if(lst->preci == 0 && lst->xvalue == 0)
		lst->str = ft_strreplace(lst->str,
				lst->str, ft_largeur(ft_atoi(lst->larg), "", lst));
	else
	{
		if (ft_atoi(lst->larg) >= 2 && ft_strchr(lst->indic, '#') != 0 &&
				ft_strchr(lst->indic, '-') == 0 && lst->larg_c == '0')
			lst->larg = ft_itoa(ft_atoi(lst->larg) - 1);
		if (lst->preci != -1)
			flag_o_preci(lst);
		else
			flag_o_nopreci(lst);
		if (ft_strchr(lst->indic, '-') != 0)
		{
			lst->larg_c = 0;
			lst->larg = ft_strjoin("-", lst->larg);
		}
		if (ft_strchr(lst->indic, '#') != 0 && lst->xvalue != 0 &&
				lst->larg_c != '0')
			lst->str = ft_strjoin("0", lst->str);
		lst->str = ft_strreplace(lst->str,
				lst->str, ft_largeur(ft_atoi(lst->larg), lst->str, lst));
		if (ft_strchr(lst->indic, '#') != 0 && lst->xvalue != 0 &&
				lst->larg_c == '0')
		{
			lst->str = ft_strjoin("0", lst->str);
		}
		lst->str = ft_strreplace(lst->str,
				lst->str, ft_largeur(ft_atoi(lst->larg), lst->str, lst));
		lst->str = ft_strlowcase(lst->str);
	}
}

void	flag_o_preci(t_lst *lst)
{
	if (lst->mode_l == 1)
	{
		lst->str = ft_strreplace(lst->str, lst->str, precision_int
				(ft_ultoa_base((unsigned long int)lst->xvalue, 8),
				 lst->preci));
	}
	else if (lst->mode_l == 2 || lst->mode_j == 1 || lst->mode_z == 1)
	{
		lst->str = ft_strreplace(lst->str, lst->str, precision_int
				(ft_ultoa_base((unsigned long long int)lst->xvalue, 8),
				 lst->preci));
	}
	else
	{
		lst->str = ft_strreplace(lst->str, lst->str,
				precision_int(ft_ultoa_base((unsigned int)lst->xvalue,
						8), lst->preci));
	}
}

void	flag_o_nopreci(t_lst *lst)
{
	if (lst->mode_l == 1)
	{
		lst->str = ft_strreplace(lst->str, lst->str,
				ft_ultoa_base((unsigned long int)lst->xvalue, 8));
	}
	else if (lst->mode_l == 2 || lst->mode_j == 1 || lst->mode_z == 1)
	{
		lst->str = ft_strreplace(lst->str, lst->str,
				ft_ultoa_base((unsigned long long int)lst->xvalue, 8));
	}
	else
		lst->str = ft_strreplace(lst->str, lst->str,
				ft_ultoa_base((unsigned int)lst->xvalue, 8));
}
