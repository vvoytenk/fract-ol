/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoytenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 14:30:03 by vvoytenk          #+#    #+#             */
/*   Updated: 2017/11/02 14:30:05 by vvoytenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void		ft_putendl_fd(char const *s, int fd)
{
	int		i;

	i = 0;
	if (s != NULL)
	{
		while (s[i] != '\0')
			putchar_fd(s[i++], fd);
		putchar_fd('\n', fd);
	}
}
