/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoytenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 18:02:06 by vvoytenk          #+#    #+#             */
/*   Updated: 2017/10/28 18:31:07 by vvoytenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	int		i;
	int		x;
	void	*adr;

	i = 0;
	x = n;
	adr = dst;
	while (i++ < x && x != 0)
		*(unsigned char *)dst++ = *(unsigned char *)src++;
	return (adr);
}
