/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoytenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 18:52:27 by vvoytenk          #+#    #+#             */
/*   Updated: 2017/10/29 14:41:32 by vvoytenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	int		i;
	int		x;
	void	*adr;

	i = 0;
	x = n;
	adr = dst;
	while (i < x && x != 0)
	{
		((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
		if (((unsigned char*)dst)[i] == (unsigned char)c)
			return (adr + i + 1);
		i++;
	}
	return (0);
}
