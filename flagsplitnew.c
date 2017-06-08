#include "ft_printf.h"

int		is_close(char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' ||
			c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'U' ||
			c == 'x' || c == 'X' || c == 'c' || c == 'C' || c == '%')
		return(1);
	return(0);
}

int		is_option(char c)
{
	if(ft_isdigit(c) || c == '#' || c == ' ' || c == '.' || c == '+' ||
			c == '-')
		return(1);
	return(0);
}

void	count_flags(t_env *env)
{
	int		i = 0;
	int		open_flag;
	int		open_str;
	env->count = 0;
	open_flag = 0;
	open_str = 0;
	while (env->format[i])
	{
		if (env->format[i] == '%' && open_flag == 0)
		{
			open_str = 0;
			open_flag = 1;
			env->count++;
		}
			
	}
}


void	flagsplit(t_env *env)
{
	count_flags(env);
	env->flag_len = (int *)malloc(sizeof(int) * env->count);
	//len_flags(env);
	int i = 0;
	ft_putstr("nombre de flags = ");
	ft_putnbr(env->count);
	ft_putchar('\n');
	/*while (i < env->count)
	{
		ft_putnbr(env->flag_len[i] + 1);
		ft_putchar('\n');
		i++;
	}*/
}

int main(int argc, char **argv)
{
	t_env	env;
	env.format = (char *)argv[1];
	flagsplit(&env);
}
