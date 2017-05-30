/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 04:03:48 by yarypert          #+#    #+#             */
/*   Updated: 2017/05/30 05:18:46 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "./Libft/libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct	s_env
{
	int bn;

}				t_env;

int		ft_printf(const char *format, ...);
char	**parse_format(char *str, va_list *args);
void	first_check(char *str);
int		count_flags(char *str);
int		analyse(va_list *args, char *format);
void	dispatcher(char *flag, va_list *args);
void	dispatcher2(char *flag, va_list *args);
void	dispatcher3(char *flag, va_list *args);
void	dispatcher4(char *flag, va_list *args);
void	flag_s(va_list *args, int bn);
void	flag_S(va_list *args, int bn);
void	flag_p(va_list *args, int bn);
void	flag_d(va_list *args, int bn);
void	flag_D(va_list *args, int bn);
void	flag_i(va_list *args, int bn);
void	flag_o(va_list *args, int bn);
void	flag_O(va_list *args, int bn);
void	flag_U(va_list *args, int bn);
void	flag_x(va_list *args, int bn);
void	flag_X(va_list *args, int bn);
void	flag_c(va_list *args, int bn);
void	flag_C(va_list *args, int bn);
void	if_bn(int bn);
void	print_tab(char **tab);

#endif
