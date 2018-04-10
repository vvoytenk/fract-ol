/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoytenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 21:03:51 by vvoytenk          #+#    #+#             */
/*   Updated: 2017/10/30 21:23:02 by vvoytenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*area;
	void	*adr;

	area = malloc(size);
	if (area == 0)
		return (NULL);
	adr = area;
	while (size-- != 0)
		*(unsigned char *)area++ = 0;
	free(area);
	return (adr);
}
