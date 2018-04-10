/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoytenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 17:36:53 by vvoytenk          #+#    #+#             */
/*   Updated: 2017/11/01 17:36:56 by vvoytenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			length(char const *s)
{
	int				i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*arr;

	i = 0;
	if (s != 0 && f != 0)
	{
		if (!(arr = (char*)malloc((length(s) + 1) * sizeof(char))))
			return (NULL);
		while (s[i] != '\0')
		{
			arr[i] = f(i, s[i]);
			i++;
		}
		arr[i] = '\0';
		return (arr);
	}
	return (NULL);
}
