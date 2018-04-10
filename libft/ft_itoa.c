/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoytenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:36:00 by vvoytenk          #+#    #+#             */
/*   Updated: 2017/11/06 16:36:02 by vvoytenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	counter(int n)
{
	int		i;

	i = 0;
	if (!n)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	int		i;
	char	*arr;
	int		dig;

	dig = n;
	i = counter(n);
	if (!(arr = (char*)malloc(i + 1)))
		return (NULL);
	arr[i--] = '\0';
	if (!n)
		arr[i] = '0';
	while (i >= 0)
	{
		if (dig < 0)
			arr[i--] = -(n % 10) + 48;
		else
			arr[i--] = n % 10 + 48;
		n /= 10;
	}
	if (dig < 0)
		arr[0] = '-';
	return (arr);
}
