/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 04:35:52 by yarypert          #+#    #+#             */
/*   Updated: 2017/06/09 07:33:41 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <unistd.h>
#include "libft.h"

void	ft_putwchar_fd(wchar_t c, int fd)
{
	if (c <= 0x7F)/*127 -> 111 1111*/
		ft_putchar_fd(c, fd);
	else if (c <= 0x7FF)/*2047 -> 111 1111 1111 */
	{
		ft_putchar_fd((c >> 6) + 0xC0, fd);/*192 -> 1100 0000 */
		ft_putchar_fd((c & 0x3F) + 0x80, fd);/*63 -> 11 1111 | 128 - 1000 0000 */
	}
	else if (c <= 0xFFFF)/*65535 -> 1111 1111 1111 1111*/
	{
		ft_putchar_fd((c >> 12) + 0xE0, fd);/*224 -> 1110 0000 */
		ft_putchar_fd(((c >> 6) & 0x3F) + 0x80, fd);/*63 -> 11 1111 | 128 -> 1000 0000*/
		ft_putchar_fd((c & 0x3F) + 0x80, fd);/*63 -> 111111 | 128 -> 1000 0000*/
	}
	else if (c <= 0x10FFFF)/*1114111 - 1 0000 1111 1111 1111 1111*/
	{
		ft_putchar_fd((c >> 18) + 0xF0, fd);/*240 -> 1111 0000*/
		ft_putchar_fd(((c >> 12) & 0x3F) + 0x80, fd);/*63 -> 111111 | 128 -> 1000 0000*/
		ft_putchar_fd(((c >> 6) & 0x3F) + 0x80, fd);/*63 -> 111111 | 128 -> 1000 0000*/
		ft_putchar_fd((c & 0x3F) + 0x80, fd);/*63 -> 111111 | 128 -> 1000 0000*/
	}
}

/* https://en.wikipedia.org/wiki/UTF-8 */
