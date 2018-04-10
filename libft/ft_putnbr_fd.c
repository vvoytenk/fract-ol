/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoytenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 20:44:31 by vvoytenk          #+#    #+#             */
/*   Updated: 2017/11/06 20:44:34 by vvoytenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void			t_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void				ft_putnbr_fd(int n, int fd)
{
	unsigned int	nbr;

	nbr = n;
	if (n < 0)
	{
		t_putchar('-', fd);
		nbr *= -1;
	}
	if (nbr >= 10)
	{
		ft_putnbr_fd(nbr / 10, fd);
		t_putchar(nbr % 10 + 48, fd);
	}
	if (nbr < 10)
		t_putchar(nbr % 10 + 48, fd);
}
