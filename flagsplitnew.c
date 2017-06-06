#include "ft_printf.h"

int		is_close(char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' ||
			c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'U' ||
			c == 'x' || c == 'X' || c == 'c' || c == 'C' || c == '%')
		return(1);
	return(0);
}

void	len_flags(t_env *env)
{
	int		i = 0;
	int		open_flag;
	int		open_str;
	int		j = 0;
	open_flag = 0;
	open_str = 0;
	if(env->format[0] == '%')
		open_flag = 1;
	else
		open_str = 1;
	while (env->format[i])
	{
		if(open_str == 0 && env->format[i] != '%')
		{
			open_str = 1;
			i++;
		}
		if(open_str == 1 && (env->format[i + 1] == '%' || env->format[i + 1] == '\0'))
		{
			open_str = 0;
			env->flag_len[j] = i;
			j++;
		}
		if(env->format[i] == '%')
		{
			open_flag = 1;
			open_str = 0;
			i++;
		}
		if (is_close(env->format[i]) && open_flag == 1)
		{
			open_flag = 0;
			env->flag_len[j] = i;
			j++;
		}
			i++;
	}
}


void	count_flags(t_env *env)
{
	int		i = 0;
	int		open_flag;
	int		open_str;
	i = 0;
	env->count = 0;
	open_flag = 0;
	open_str = 0;
	if(env->format[0] == '%')
		open_flag = 1;
	else
		open_str = 1;
	while (env->format[i])
	{
		if(open_str == 0 && env->format[i] != '%')
		{
			open_str = 1;
			i++;
		}
		if(open_str == 1 && (env->format[i + 1] == '%' || env->format[i + 1] == '\0'))
		{
			open_str = 0;
			env->count++;
		}
		if(env->format[i] == '%')
		{
			open_flag = 1;
			open_str = 0;
			i++;
		}
		if (is_close(env->format[i]) && open_flag == 1)
		{
			open_flag = 0;
			env->count++;
		}
			i++;
	}
}


void	flagsplit(t_env *env)
{
	count_flags(env);
	env->flag_len = (int *)malloc(sizeof(int) * env->count);
	len_flags(env);
	int i = 0;
	while (i < env->count)
	{
		ft_putnbr(env->flag_len[i] + 1);
		ft_putchar('\n');
		i++;
	}
}

int main(int argc, char **argv)
{
	t_env	env;
	env.format = (char *)argv[1];
	flagsplit(&env);
}
