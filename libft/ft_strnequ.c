/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoytenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 18:50:04 by vvoytenk          #+#    #+#             */
/*   Updated: 2017/11/01 18:50:07 by vvoytenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int		i;
	int		len;

	i = 0;
	len = n;
	if (s1 != NULL && s2 != NULL)
	{
		while ((s1[i] != '\0' || s2[i] != '\0') && (i < len))
		{
			if (s1[i] != s2[i])
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}
