/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoytenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 20:30:38 by vvoytenk          #+#    #+#             */
/*   Updated: 2017/11/01 20:30:40 by vvoytenk         ###   ########.fr       */
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

char		*ft_strtrim(char const *s)
{
	char	*arr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s == 0)
		return (0);
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i] != 0)
		i++;
	if (i == length(s))
		return (arr = ft_strnew(0));
	j = length(s) - 1;
	while ((s[j] == ' ' || s[j] == '\n' || s[j] == '\t') && j != 0)
		j--;
	arr = ft_strsub(s, i, (j - i + 1));
	return (arr);
}
