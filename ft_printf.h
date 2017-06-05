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
	va_list	args;
	int		flag_nb;
	char **flags;
}				t_env;

int		ft_printf(const char *format, ...);
int		parse_format(char *str, t_env *env);
void	first_check(char *str);
int		count_flags(char *str);
void	dispatcher1(t_env *env);
void	dispatcher2(t_env *env, int i);
void	dispatcher3(t_env *env, int i);
void	dispatcher4(t_env *env, int i);
void	dispatcher5(t_env *env, int i);
void	flag_s(t_env *env, int i);
void	flag_S(t_env *env, int i);
void	flag_p(t_env *env, int i);
void	flag_d(t_env *env, int i);
void	flag_D(t_env *env, int i);
void	flag_i(t_env *env, int i);
void	flag_o(t_env *env, int i);
void	flag_O(t_env *env, int i);
void	flag_U(t_env *env, int i);
void	flag_x(t_env *env, int i);
void	flag_X(t_env *env, int i);
void	flag_c(t_env *env, int i);
void	flag_C(t_env *env, int i);
void	print_tab(char **tab);
char	**flagsplit(char *str);
char	**resplit(char **str, int flag_nb, int *flag_len);
int		*lenflags(char *str, int count);
int		*lenflags2(char *str, int *len, int count);
int		countflags(char *str);

#endif
