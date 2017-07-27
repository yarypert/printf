#include "includes/ft_printf.h"

void	flag_s(t_env *env, t_lst *lst)
{
	lst->str = ft_strreplace(lst->str, lst->str, va_arg(env->args,char*));
}

void	flag_bigs(t_env *env, t_lst *lst)
{
}

void	flag_p(t_env *env, t_lst *lst)
{
}

void	flag_d(t_env *env, t_lst *lst)
{
	lst->str = ft_strreplace(lst->str, lst->str, ft_itoa(va_arg(env->args,int)));
}

void	flag_bigd(t_env *env, t_lst *lst)
{
	lst->str = ft_strreplace(lst->str, lst->str, ft_ltoa(va_arg(env->args,int)));
}
