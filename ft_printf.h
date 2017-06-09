/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 04:03:48 by yarypert          #+#    #+#             */
/*   Updated: 2017/06/09 05:02:59 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./Libft/libft.h"
# include "color.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdarg.h>

typedef struct		s_lst
{
	char			*str;
	int				flag;
	struct s_lst	*next;
	struct s_lst	*prev;
}					t_lst;

typedef struct		s_env
{
	va_list			args;
	int				ret;
	char			*format;
}					t_env;

int					ft_printf(const char *format, ...);
void				flag_s(t_env *env, int i);
void				flag_bigs(t_env *env, int i);
void				flag_p(t_env *env, int i);
void				flag_d(t_env *env, int i);
void				flag_bigd(t_env *env, int i);
void				flag_i(t_env *env, int i);
void				flag_o(t_env *env, int i);
void				flag_bigo(t_env *env, int i);
void				flag_bigu(t_env *env, int i);
void				flag_x(t_env *env, int i);
void				flag_bigx(t_env *env, int i);
void				flag_c(t_env *env, int i);
void				flag_bigc(t_env *env, int i);

void				check_lst(t_lst *lst);
int					iscc(char c);
t_lst				*make_lst(char *str, t_lst *lst);
t_lst				*ftp_parsing(char *str);
int					process(t_env *env, t_lst *lst);

#endif
