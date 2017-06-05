#include "ft_printf.h"

void	flag_s(t_env *env, int i)
{
	env->flags[i] = ft_strreplace(env->flags[i], env->flags[i], va_arg(env->args, char *));
}

void	flag_S(t_env *env, int i)
{
}

void	flag_p(t_env *env, int i)
{
}

void	flag_d(t_env *env, int i)
{
}

void	flag_D(t_env *env, int i)
{
}
