/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <aancel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 02:49:45 by aancel            #+#    #+#             */
/*   Updated: 2017/07/31 02:35:30 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "color.h"
# include "../includes/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

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
	int				larg_nbr;
	int				preci;
	char			type;
	struct s_lst	*next;
	struct s_lst	*prev;
}				t_lst;

#endif
