/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 04:03:48 by yarypert          #+#    #+#             */
/*   Updated: 2017/05/16 14:53:52 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "./Libft/libft.h"
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
char	**parse_format(char *str);

#endif
