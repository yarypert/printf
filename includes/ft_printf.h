/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <aancel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 02:49:45 by aancel            #+#    #+#             */
/*   Updated: 2017/07/31 06:14:57 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "color.h"
# include "../Libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <locale.h>

# define ABS(x) ((x) < 0 ? -(x) : (x))

typedef struct	s_lst
{
	char			*str;
	int				flag;
	int				mode_h;
	int				mode_l;
	int				mode_j;
	int				mode_z;
	char			*indic;
	char			*larg;
	char			larg_c;
	char			larg_nbr;
	int				preci;
	char			type;
	struct s_lst	*next;
	struct s_lst	*prev;
}				t_lst;

typedef struct s_env
{
	va_list			args;
	int				ret;
	char*			format;
}				t_env;


void	ft_dispatcher(t_env *env, t_lst *lst);
void	ft_chooseflag(t_env *env, t_lst *lst);
void	flag_s(t_env *env, t_lst *lst);
void	flag_bigs(t_env *env, t_lst *lst);
void	flag_p(t_env *env, t_lst *lst);
void	flag_d(t_env *env, t_lst *lst);
void	flag_bigd(t_env *env, t_lst *lst);
void	flag_o(t_env *env, t_lst *lst);
void	flag_bigo(t_env *env, t_lst *lst);
void	flag_bigu(t_env *env, t_lst *lst);
void	flag_x(t_env *env, t_lst *lst);
void	flag_bigx(t_env *env, t_lst *lst);
void	flag_c(t_env *env, t_lst *lst);
void	flag_bigc(t_env *env, t_lst *lst);
void	flag_b(t_env *env, t_lst *lst);
int		ft_printf(const char *format, ...);
void	ft_err(int error);
int		iscc(char c);
int		set_val_flag(char c);
t_lst	*make_lst(char *str, t_lst *lst);
void	init_flag(t_lst *lst);
void	set_op(char c, t_lst *lst);
int		isop(char c);
float	ft_ftof(char *str, int *i);
int		check_flag(char *flag2, t_lst *lst);
int		valid_option_flag(t_lst *lst);
void	check_lst(t_lst *lst);
t_lst	*ftp_parsing(char *str);
void	aff_valid_lst(t_lst *lst);
int		process(t_env *env, t_lst *lst);
void	print_list(t_env *env, t_lst *lst);
char	*precision_string(char *str, int prec);
char	*precision_int(char *str, int prec);

#endif
