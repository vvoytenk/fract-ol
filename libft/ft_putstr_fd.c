/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoytenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 14:27:28 by vvoytenk          #+#    #+#             */
/*   Updated: 2017/11/02 14:27:30 by vvoytenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void		ft_putstr_fd(char const *s, int fd)
{
	int		i;

	i = 0;
	if (s != NULL)
	{
		while (s[i] != '\0')
			putchar_fd(s[i++], fd);
	}
}
