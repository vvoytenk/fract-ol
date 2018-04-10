/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoytenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 17:16:11 by vvoytenk          #+#    #+#             */
/*   Updated: 2017/10/30 18:29:23 by vvoytenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		i;
	int		j;
	char	*temp;
	size_t	t;

	if (*little == '\0')
		return (((char *)big));
	while (*big != '\0' && (len != 0))
	{
		i = 0;
		j = 0;
		t = len;
		temp = (char *)big;
		while ((little[j++] == big[i++]) && (t != 0))
		{
			if (little[j] == '\0')
				return (temp);
			t--;
		}
		big++;
		len--;
	}
	return (0);
}
