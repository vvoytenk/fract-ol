/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoytenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 14:42:09 by vvoytenk          #+#    #+#             */
/*   Updated: 2017/10/29 16:44:21 by vvoytenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dst, const void *src, size_t len)
{
	int				i;
	int				x;
	void			*adr;

	i = 0;
	x = len;
	adr = dst;
	if (src > dst)
		ft_memcpy(dst, src, len);
	else
		while (x > 0)
		{
			((unsigned char*)dst)[x - 1] = ((unsigned char*)src)[x - 1];
			x--;
		}
	return (adr);
}
