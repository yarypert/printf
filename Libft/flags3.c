#include "libft.h"

void	flag_c(t_env *env, t_lst *lst)
{
	lst->str = ft_strreplace(lst->str, lst->str,
			ft_ctoa(va_arg(env->args, int)));
}

void	flag_bigc(t_env *env, t_lst *lst)
{
	(void)env;
	(void)lst;
}

void	flag_b(t_env *env, t_lst *lst)
{
	if (lst->preci != -1)
	{
		if(lst->mode_l == 1)
			lst->str = ft_strreplace(lst->str, lst->str, precision_int
			(ft_ltoa_base(va_arg(env->args, long int), 2), lst->preci));
		if(lst->mode_l == 2 || lst->mode_j == 1)
			lst->str = ft_strreplace(lst->str, lst->str, precision_int
			(ft_ltoa_base(va_arg(env->args, long long int), 2), lst->preci));
		else
			lst->str = ft_strreplace(lst->str, lst->str, precision_int
			(ft_itoa_base(va_arg(env->args, int), 2), lst->preci));
	}
	else
	{
		if(lst->mode_l == 1)
		lst->str = ft_strreplace(lst->str, lst->str,
			ft_ltoa_base(va_arg(env->args, long int), 2));
		if(lst->mode_l == 2 || lst->mode_j == 1)
		lst->str = ft_strreplace(lst->str, lst->str,
			ft_ltoa_base(va_arg(env->args, long long int), 2));
		else
		lst->str = ft_strreplace(lst->str, lst->str,
			ft_itoa_base(va_arg(env->args, int), 2));
	}
	if(ft_strcmp(lst->indic , "-") == 0)
		lst->larg = ft_strjoin("-", lst->larg);
	lst->str = ft_strreplace(lst->str, lst->str, ft_largeur(ft_atoi(lst->larg), lst->str, lst));
}

void	flag_percent(t_lst *lst)
{
	if(ft_strcmp(lst->indic , "-") == 0)
		lst->larg = ft_strjoin("-", lst->larg);
	lst->str = ft_strreplace(lst->str, lst->str, "%");
	lst->str = ft_largeur(ft_atoi(lst->larg), lst->str, lst);
}
