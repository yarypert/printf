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
		lst->str = ft_strreplace(lst->str, lst->str, precision_int
			(ft_itobin(va_arg(env->args,int)), lst->preci));
	}
	else
	{
		lst->str = ft_strreplace(lst->str, lst->str,
				ft_itobin(va_arg(env->args,int)));
	}
//		lst->str = ft_strreplace(lst->str, lst->str, ft_largeur
//			(lst->preci, ft_itobin(va_arg(env->args,int))));
}
