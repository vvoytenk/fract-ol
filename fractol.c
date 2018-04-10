/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoytenk <vvoytenk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 17:55:26 by vvoytenk          #+#    #+#             */
/*   Updated: 2018/04/10 17:55:28 by vvoytenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void fractol(char *file)
{
    if (ft_strcmp(file, "Julia") == 0)
        julia();
    else if (ft_strcmp(file, "Mandelbrot") == 0)
        mandel();
    else
        error(2);
}
