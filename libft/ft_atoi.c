/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoytenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 19:53:10 by vvoytenk          #+#    #+#             */
/*   Updated: 2017/11/01 18:41:23 by vvoytenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int				iswhitespaces(char c)
{
	return (c == '\n' || c == ' ' || c == '\t' ||
		c == '\v' || c == '\f' || c == '\r');
}

int						ft_atoi(const char *str)
{
	unsigned long int	dig;
	int					i;
	int					sign;

	i = 0;
	dig = 0;
	sign = 1;
	while (iswhitespaces(str[i]))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		dig = (dig * 10 + str[i] - 48);
		if (str[i] < '0' || str[i] > '9')
			return (dig * sign);
		i++;
	}
	if (dig >= 9223372036854775807 && sign == 1)
		return (-1);
	else if (dig > 9223372036854775807 && sign == -1)
		return (0);
	return (dig * sign);
}
