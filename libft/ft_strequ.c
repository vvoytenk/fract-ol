/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoytenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 17:52:38 by vvoytenk          #+#    #+#             */
/*   Updated: 2017/11/01 17:52:40 by vvoytenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	length(char const *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

int			ft_strequ(char const *s1, char const *s2)
{
	int		l1;
	int		l2;
	int		i;

	i = 0;
	if (s1 != NULL && s2 != NULL)
	{
		l1 = length(s1);
		l2 = length(s2);
		if (l1 == l2)
		{
			while (s1[i] != '\0' || s2[i] != '\0')
			{
				if (s1[i] != s2[i])
					return (0);
				i++;
			}
			return (1);
		}
	}
	return (0);
}
