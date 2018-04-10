/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoytenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 18:58:54 by vvoytenk          #+#    #+#             */
/*   Updated: 2017/10/28 17:02:00 by vvoytenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int	i;
	int	length;
	int *arg;

	i = 0;
	length = len;
	arg = b;
	while (i++ < length)
		*(unsigned char *)b++ = (unsigned char)c;
	return (arg);
}
