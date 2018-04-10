/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoytenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 17:16:35 by vvoytenk          #+#    #+#             */
/*   Updated: 2017/11/01 17:16:37 by vvoytenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	length(char const *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*arr;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(arr = (char *)malloc(sizeof(char) * (length(s) + 1))))
		return (NULL);
	if (s != 0 && f != 0)
	{
		while (s[i] != '\0')
		{
			arr[i] = f(s[i]);
			i++;
		}
		arr[i] = 0;
		return (arr);
	}
	return (0);
}
