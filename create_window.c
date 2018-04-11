/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoytenk <vvoytenk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 20:21:00 by vvoytenk          #+#    #+#             */
/*   Updated: 2018/03/17 20:21:00 by vvoytenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	create_window(t_fract *fract)
{
	fract->mlx = mlx_init();
	fract->win = mlx_new_window(fract->mlx, WID, HEI, "Fractol");
}
