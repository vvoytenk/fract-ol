/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoytenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 17:45:21 by vvoytenk          #+#    #+#             */
/*   Updated: 2017/10/29 18:44:23 by vvoytenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	dstlen(const char *s, size_t size)
{
	int		i;

	i = 0;
	while (s[i] != '\0' && size-- != 0)
		i++;
	return (i);
}

static int	len(const char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	int		j;
	int		n;

	i = (size_t)len(dst);
	j = (size_t)dstlen(dst, size);
	n = len(src);
	if (size < i)
		return (j + n);
	while (i < (size - 1) && *src != '\0')
		dst[i++] = *src++;
	dst[i] = 0;
	return (j + n);
}
