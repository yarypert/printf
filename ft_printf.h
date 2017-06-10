/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 04:03:48 by yarypert          #+#    #+#             */
/*   Updated: 2017/06/10 16:07:55 by yarypert         ###   ########.fr       */
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
# include <locale.h>

	char            *str;
	int                flag;
	int                flag_h;
	int                flag_l;
	int                flag_j;
	int                flag_z;
	int                flag_more;
	int                flag_less;
	int                flag_nbr;
	int                flag_hash;
	struct s_lst    *next;
	struct s_lst    *prev;



typedef struct		s_lst
{
	char			*str;
	int				mod_h;
	int				mod_l;
	int				mod_j;
	int				mod_z;
	int				opt_more;
	int				opt_less;
	int				opt_nbr;
	int				opt_hash;
	int				opt_spc;
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
void				flag_s(t_env *env, t_lst *lst);
void				flag_bigs(t_env *env, t_lst *lst);
void				flag_p(t_env *env, t_lst *lst);
void				flag_d(t_env *env, t_lst *lst);
void				flag_bigd(t_env *env, t_lst *lst);
void				flag_o(t_env *env, t_lst *lst);
void				flag_bigo(t_env *env, t_lst *lst);
void				flag_bigu(t_env *env, t_lst *lst);
void				flag_x(t_env *env, t_lst *lst);
void				flag_bigx(t_env *env, t_lst *lst);
void				flag_c(t_env *env, t_lst *lst);
void				flag_bigc(t_env *env, t_lst *lst);
void				flag_b(t_env *env, t_lst *lst);


void				ft_chooseflag(t_env *env, t_lst *lst);
void				ft_dispatcher(t_env *env, t_lst *lst);
void				print_list(t_env *env, t_lst *lst);
int					iscc(char c);
t_lst				*make_lst(char *str, t_lst *lst);
t_lst				*ftp_parsing(char *str);
int					process(t_env *env, t_lst *lst);

#endif
