/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoytenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 18:30:05 by vvoytenk          #+#    #+#             */
/*   Updated: 2017/10/30 18:45:29 by vvoytenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	int	j;

	j = 0;
	while (s1[j] != '\0')
	{
		if (s1[j] != s2[j])
			return ((unsigned char)s1[j] - (unsigned char)s2[j]);
		j++;
	}
	if (s1[j] != s2[j])
		return ((unsigned char)s1[j] - (unsigned char)s2[j]);
	return (0);
}
