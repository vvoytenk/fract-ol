/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoytenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 13:57:39 by vvoytenk          #+#    #+#             */
/*   Updated: 2017/11/02 13:57:42 by vvoytenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putendl(char const *s)
{
	int		i;

	i = 0;
	if (s != NULL)
	{
		while (s[i] != '\0')
			putchar(s[i++]);
		putchar('\n');
	}
}
