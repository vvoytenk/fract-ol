/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoytenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 16:40:26 by vvoytenk          #+#    #+#             */
/*   Updated: 2017/10/29 17:28:54 by vvoytenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	len(char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char		*ft_strcat(char *s1, const char *s2)
{
	int		j;
	int		i;

	j = 0;
	i = len(s1);
	while (s2[j] != '\0')
		s1[i++] = s2[j++];
	s1[i] = '\0';
	return (s1);
}
