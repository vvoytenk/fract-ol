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

 int    fractol(t_fractol *f)
{
    create_image(f);
    if (f->numF == 1)
        julia(f);
    if (f->numF == 2)
        mandel(f);
    if (f->numF == 3)
        buddha(f);
     mlx_put_image_to_window(f->mlx, f->win, f->image.ptr, 0, 0);
     mlx_destroy_image(f->mlx, f->image.ptr);
    return (0);
}

int     countIter(t_fractol *f)
{
    int i;

    i = 0;
    while (f->j->Re * f->j->Re + f->j->Im * f->j->Im <= 4)
    {
        f->j->temp = f->j->Re * f->j->Re - f->j->Im * f->j->Im + f->j->cRe;
        f->j->Im = 2 * f->j->Re * f->j->Im + f->j->cIm;
        f->j->Re = f->j->temp;
        if (i > f->j->maxIter)
            break;
        i++;
    }
    return (i);
}