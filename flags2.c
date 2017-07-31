#include "includes/ft_printf.h"

void	flag_o(t_env *env, t_lst *lst)
{
	if (lst->preci != -1)
	{
		lst->str = ft_strreplace(lst->str, lst->str, precision_int(ft_itoa_base
				(va_arg(env->args, int), 8), lst->preci));
	}
	else
	{
		lst->str = ft_strreplace(lst->str, lst->str, ft_itoa_base
				(va_arg(env->args, int), 8));
	}
}

void	flag_bigo(t_env *env, t_lst *lst)
{
	if (lst->preci != -1)
	{
		lst->str = ft_strreplace(lst->str, lst->str, precision_int(ft_ltoa_base
				(va_arg(env->args, long), 8), lst->preci));
	}
	else
	{
		lst->str = ft_strreplace(lst->str, lst->str, ft_ltoa_base
				(va_arg(env->args, long), 8));
	}
}

void	flag_bigu(t_env *env, t_lst *lst)
{
}

void	flag_x(t_env *env, t_lst *lst)
{
	if (lst->preci != -1)
	{
		lst->str = ft_strreplace(lst->str, lst->str, precision_int(ft_strlowcase
				(ft_itoa_base(va_arg(env->args, int), 16)),lst->preci));
	}
	else
	{
		lst->str = ft_strreplace(lst->str, lst->str, ft_strlowcase
				(ft_itoa_base(va_arg(env->args, int), 16)));
	}
}

void	flag_bigx(t_env *env, t_lst *lst)
{
	if (lst->preci != -1)
	{
		lst->str = ft_strreplace(lst->str, lst->str, precision_int(ft_strupcase
				(ft_itoa_base(va_arg(env->args, long), 16)), lst->preci));
	}
	else
	{
		lst->str = ft_strreplace(lst->str, lst->str, ft_strupcase
				(ft_itoa_base(va_arg(env->args, long), 16)));
	}
}
