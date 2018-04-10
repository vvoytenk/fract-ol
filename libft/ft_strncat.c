/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoytenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 17:29:39 by vvoytenk          #+#    #+#             */
/*   Updated: 2017/10/29 17:44:37 by vvoytenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		i;
	size_t	j;

	j = 0;
	i = len(s1);
	while (j < n && s2[j] != 0)
		s1[i++] = s2[j++];
	s1[i] = '\0';
	return (s1);
}
