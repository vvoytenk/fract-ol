/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoytenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 15:25:55 by vvoytenk          #+#    #+#             */
/*   Updated: 2017/11/01 15:26:01 by vvoytenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	size_t	i;
	char	*str;

	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == 0)
		return (0);
	i = 0;
	while (i <= size)
		str[i++] = '\0';
	return (str);
}
