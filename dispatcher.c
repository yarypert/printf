#include "ft_printf.h"

void	dispatcher(char *flag, va_list *args)
{
	if(flag[ft_strlen(flag) - 1] == 's')
		flag_s(args, 0);
	if(flag[ft_strlen(flag) - 1] == 'S')
		flag_S(args, 0);
	if(flag[ft_strlen(flag) - 1] == 'p')
		flag_p(args, 0);
	if(flag[ft_strlen(flag) - 1] == 'd')
		flag_d(args, 0);
	if(flag[ft_strlen(flag) - 1] == 'D')
		flag_D(args, 0);
	if(flag[ft_strlen(flag) - 1] == 'i')
		flag_i(args, 0);
	if(flag[ft_strlen(flag) - 1] == 'o')
		flag_o(args, 0);
	dispatcher2(flag, args);
}

void	dispatcher2(char *flag, va_list *args)
{
	if(flag[ft_strlen(flag) - 1] == 'O')
		flag_O(args, 0);
	if(flag[ft_strlen(flag) - 1] == 'U')
		flag_U(args, 0);
	if(flag[ft_strlen(flag) - 1] == 'x')
		flag_x(args, 0);
	if(flag[ft_strlen(flag) - 1] == 'X')
		flag_X(args, 0);
	if(flag[ft_strlen(flag) - 1] == 'c')
		flag_c(args, 0);
	if(flag[ft_strlen(flag) - 1] == 'C')
		flag_C(args, 0);
	dispatcher3(flag, args);
}

void	dispatcher3(char *flag, va_list *args)
{
	if(flag[ft_strlen(flag) - 1] == '\n' && flag[ft_strlen(flag) - 2] == 's')
		flag_s(args, 1);
	if(flag[ft_strlen(flag) - 1] == '\n' && flag[ft_strlen(flag) - 2] == 'S')
		flag_S(args, 1);
	if(flag[ft_strlen(flag) - 1] == '\n' && flag[ft_strlen(flag) - 2] == 'p')
		flag_p(args, 1);
	if(flag[ft_strlen(flag) - 1] == '\n' && flag[ft_strlen(flag) - 2] == 'd')
		flag_d(args, 1);
	if(flag[ft_strlen(flag) - 1] == '\n' && flag[ft_strlen(flag) - 2] == 'D')
		flag_D(args, 1);
	if(flag[ft_strlen(flag) - 1] == '\n' && flag[ft_strlen(flag) - 2] == 'i')
		flag_i(args, 1);
	if(flag[ft_strlen(flag) - 1] == '\n' && flag[ft_strlen(flag) - 2] == 'o')
		flag_o(args, 1);
	if(flag[ft_strlen(flag) - 1] == '\n' && flag[ft_strlen(flag) - 2] == 'O')
		flag_O(args, 1);
	if(flag[ft_strlen(flag) - 1] == '\n' && flag[ft_strlen(flag) - 2] == 'U')
		flag_U(args, 1);
	if(flag[ft_strlen(flag) - 1] == '\n' && flag[ft_strlen(flag) - 2] == 'x')
		flag_x(args, 1);
	if(flag[ft_strlen(flag) - 1] == '\n' && flag[ft_strlen(flag) - 2] == 'X')
		flag_X(args, 1);
	if(flag[ft_strlen(flag) - 1] == '\n' && flag[ft_strlen(flag) - 2] == 'c')
		flag_c(args, 1);
	if(flag[ft_strlen(flag) - 1] == '\n' && flag[ft_strlen(flag) - 2] == 'C')
		flag_C(args, 1);
}
