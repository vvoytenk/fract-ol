/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoytenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 19:05:15 by vvoytenk          #+#    #+#             */
/*   Updated: 2017/11/01 19:05:18 by vvoytenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*arr;
	size_t	i;

	i = 0;
	if (s != NULL)
	{
		if (!(arr = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		while (i < len && s[start + i] != '\0')
		{
			arr[i] = s[start + i];
			i++;
		}
		arr[i] = 0;
		return (arr);
	}
	return (0);
}
