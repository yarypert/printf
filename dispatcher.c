#include "ft_printf.h"

void	dispatcher1(t_env *env)
{
	int i = 0;
	while (i < env->flag_nb)
	{
		dispatcher2(env, i);
		dispatcher3(env, i);
		dispatcher4(env, i);
		dispatcher5(env, i);
		i++;
	}
}

void	dispatcher2(t_env *env, int i)
{
	int j = 0;
	int flag_percent = 0;
	while (j < ft_strlen(env->flags[i]))
	{
		if(env->flags[i][j] == '%')
			flag_percent = 1;
		if (env->flags[i][j] == 's' && flag_percent == 1)
		{
			flag_s(env, i);
			flag_percent = 0;
		}
		if (env->flags[i][j] == 'S' && flag_percent == 1)
		{
			flag_S(env, i);
			flag_percent = 0;
		}
		if (env->flags[i][j] == 'p' && flag_percent == 1)
		{
			flag_p(env, i);
			flag_percent = 0;
		}
		if (env->flags[i][j] == 'd' && flag_percent == 1)
		{
			flag_d(env, i);
			flag_percent = 0;
		}
		if (env->flags[i][j] == 'D' && flag_percent == 1)
		{
			flag_D(env, i);
			flag_percent = 0;
		}
		if (env->flags[i][j] == 'i' && flag_percent == 1)
		{
			flag_i(env, i);
			flag_percent = 0;
		}
		if (env->flags[i][j] == 'o' && flag_percent == 1)
		{
			flag_o(env, i);
			flag_percent = 0;
		}
		if (env->flags[i][j] == 'O' && flag_percent == 1)
		{
			flag_O(env, i);
			flag_percent = 0;
		}
		if (env->flags[i][j] == 'U' && flag_percent == 1)
		{
			flag_U(env, i);
			flag_percent = 0;
		}
		if (env->flags[i][j] == 'x' && flag_percent == 1)
		{
			flag_x(env, i);
			flag_percent = 0;
		}
		if (env->flags[i][j] == 'X' && flag_percent == 1)
		{
			flag_X(env, i);
			flag_percent = 0;
		}
		if (env->flags[i][j] == 'c' && flag_percent == 1)
		{
			flag_c(env, i);
			flag_percent = 0;
		}
		if (env->flags[i][j] == 'C' && flag_percent == 1)
		{
			flag_C(env, i);
			flag_percent = 0;
		}
		j ++;
	}
}

void	dispatcher3(t_env *env, int i)
{
	
}

void	dispatcher4(t_env *env, int i)
{
	
}

void	dispatcher5(t_env *env, int i)
{
	
}
