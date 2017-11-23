/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 00:49:27 by yarypert          #+#    #+#             */
/*   Updated: 2017/11/23 16:07:54 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 32
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <wchar.h>
# include <locale.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <math.h>
# include <stdio.h>
# include "../includes/color.h"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memalloc(size_t size);

void				ft_bzero(void *s, size_t n);
void				ft_memdel(void **ap);
void				ft_strdel(char **as);
void				ft_putchar(char c);
void				ft_putwchar(wchar_t c);
void				ft_putstr(char *str);
void				ft_putwstr(wchar_t *s);
void				ft_putendl(char const *str);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putwstr_fd(wchar_t *s, int fd);
void				ft_putwchar_fd(wchar_t c, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_strclr(char *s);
void				ft_striter(char *s, void(*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_void(void);
void				ft_error(char *str);

int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isspace(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_str_is_uppercase(char *str);
int					ft_str_is_printable(char *str);
int					ft_str_is_numeric(char *str);
int					ft_str_is_lowercase(char *str);
int					ft_str_is_alpha(char *str);
int					ft_sqrt(int nb);
int					ft_power(int nb, int power);
int					ft_factorial(int nb);
int					ft_is_prime(int nb);
int					ft_str_is_printable(char *str);
int					ft_isspace(int c);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_pgcd(int n1, int n2);
int					get_next_line(int fd, char **line);
int					ft_abs(int n);

size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(char const *str);

char				**ft_strsplit(char const *s, char c);
char				*ft_itoa_base(int value, int base);
char				*ft_ltoa_base(long int value, int base);
char				*ft_imtoa_base(intmax_t value, int base);
char				*ft_uimtoa_base(uintmax_t value, int base);
char				*ft_ultoa_base(unsigned long long int value, int base);
char				*ft_ctoa(char c);
char				*ft_itobin(int nb);
char				*ft_lltobin(long long nb);
char				*ft_itoa(int n);
char				*ft_ltoa(long int n);
char				*ft_lltoa(long long int n);
char				*ft_strdup(char const *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strtrim(char const *s);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strnew(size_t size);
char				*ft_strupcase(char *str);
char				*ft_strlowcase(char *str);
char				*ft_strupcase(char *str);
char				*ft_strlowcase(char *str);
char				*ft_strcapitalize(char *str);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strrev(char *str);
char				*ft_strreplace(char *s1, char *old, char *new);
char				*ft_strappend(char *str1, char *str2);

t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);

typedef struct		s_lst
{
	char			*argu;
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
	char			*sharp;
	struct s_lst	*next;
	struct s_lst	*prev;
	unsigned long long int xvalue;
}					t_lst;

typedef struct		s_env
{
	va_list			args;
	int				ret;
	char			*format;
}					 t_env;


void				ft_dispatcher(t_env *env, t_lst *lst);
void				ft_chooseflag(t_env *env, t_lst *lst);
void				ft_chooseflag2(t_env *env, t_lst *lst);
void				flag_percent(t_env *env, t_lst *lst);
void				flag_s(t_env *env, t_lst *lst);
void				flag_s_preci(t_env *env, t_lst *lst);
void				flag_s_nopreci(t_env *env, t_lst *lst);
void				flag_bigs(t_env *env, t_lst *lst);
void				flag_p(t_env *env, t_lst *lst);
void				flag_d(t_env *env, t_lst *lst);
void				flag_d_preci(t_env *env, t_lst *lst);
void				flag_d_nopreci(t_env *env, t_lst *lst);
void				flag_bigd(t_env *env, t_lst *lst);
void				flag_o(t_env *env, t_lst *lst);
void				flag_o_preci(t_env *env, t_lst *lst);
void				flag_o_nopreci(t_env *env, t_lst *lst);
void				flag_u(t_env *env, t_lst *lst);
void				flag_u_preci(t_env *env, t_lst *lst);
void				flag_u_nopreci(t_env *env, t_lst *lst);
void				flag_bigo(t_env *env, t_lst *lst);
void				flag_bigo_preci(t_env *env, t_lst *lst);
void				flag_bigo_nopreci(t_env *env, t_lst *lst);
void				flag_bigu(t_env *env, t_lst *lst);
void				flag_bigu_preci(t_env *env, t_lst *lst);
void				flag_bigu_nopreci(t_env *env, t_lst *lst);
void				flag_x(t_env *env, t_lst *lst);
void				flag_x_preci(t_lst *lst);
void				flag_x_precisharp(t_lst *lst);
void				flag_x_noprecisharp(t_lst *lst);
void				flag_x_nopreci(t_lst *lst);
void				flag_bigx(t_env *env, t_lst *lst);
void				flag_c(t_env *env, t_lst *lst);
void				flag_bigc(t_env *env, t_lst *lst);
void				flag_b(t_env *env, t_lst *lst);
void				flag_b_preci(t_env *env, t_lst *lst);
void				flag_b_nopreci(t_env *env, t_lst *lst);
int					ft_printf(const char *format, ...);
void				ft_err(int error);
int					iscc(char c);
int					set_val_flag(char c);
t_lst				*make_lst(char *str, t_lst *lst);
void				init_flag(t_lst *lst);
void				set_op(char c, t_lst *lst);
int					isop(char c);
float				ft_ftof(char *str, int *i);
int					check_flag(char *flag2, t_lst *lst);
int					valid_option_flag(t_lst *lst);
void				check_lst(t_lst *lst);
t_lst				*ftp_parsing(char *str);
void				aff_valid_lst(t_lst *lst);
int					process(t_env *env, t_lst *lst);
void				print_list(t_env *env, t_lst *lst);
char				*precision_string(char *str, int prec);
char				*precision_int(char *str, int prec);
char				*ft_largeur(int largeur, char *str, t_lst *lst);
int					ft_nbrhexlen(int cp);
char				*ft_putpp(void *p);
char				*ft_getwchar(wchar_t c);



#endif
