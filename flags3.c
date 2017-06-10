#include "ft_printf.h"

void	flag_c(t_env *env, t_lst *lst)
{
	lst->str = ft_strreplace(lst->str, lst->str, ft_ctoa(va_arg(env->args, int)));
}

void	flag_bigc(t_env *env, t_lst *lst)
{
}

void	flag_b(t_env *env, t_lst *lst)
{
	lst->str = ft_strreplace(lst->str, lst->str, ft_itobin(va_arg(env->args,int)));
}
