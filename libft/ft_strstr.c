/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoytenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 19:33:56 by vvoytenk          #+#    #+#             */
/*   Updated: 2017/10/29 20:15:58 by vvoytenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int j;
	int zaz;

	i = 0;
	zaz = -1;
	if (little[0] == '\0')
		return (&((char *)big)[i]);
	while (big[i] != '\0')
	{
		j = 0;
		zaz++;
		i = zaz;
		while (big[i] == little[j])
		{
			if (little[j + 1] == '\0')
				return (&((char *)big)[zaz]);
			i++;
			j++;
		}
	}
	return (0);
}
