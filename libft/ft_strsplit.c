/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoytenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 12:54:06 by vvoytenk          #+#    #+#             */
/*   Updated: 2017/11/02 12:54:14 by vvoytenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int		i;
	int		words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static int	count_elem(char const *s, char c, int i)
{
	int		n;

	n = 0;
	while (s[i] != '\0' && s[i + 1] != c)
	{
		i++;
		n++;
	}
	return (n);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		i;
	int		j;
	int		n;

	i = 0;
	j = 0;
	if (s == NULL || c == '\0'
		|| !(arr = (char**)malloc((count_words(s, c) + 1) * sizeof(char*))))
		return (NULL);
	while ((i = (s[i] == c) ? (i + 1) : i) != -1 && s[i] != '\0')
	{
		if (s[i] != c)
		{
			if (!(arr[j] = (char*)malloc(count_elem(s, c, i) + 1)))
				return (NULL);
			n = 0;
			while (s[i] != c && s[i] != '\0')
				arr[j][n++] = s[i++];
			arr[j++][n] = '\0';
		}
	}
	arr[j] = 0;
	return (arr);
}
