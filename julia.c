/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoytenk <vvoytenk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 19:31:45 by vvoytenk          #+#    #+#             */
/*   Updated: 2018/04/13 19:31:46 by vvoytenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex   initial_julia(t_complex *jul)
{
    jul->cRe = 0;
    jul->cIm = 0;
    jul->maxIter = 30;
    jul->scale = 5;
    jul->flag = 1;
    jul->zoomX = 0;
    jul->zoomY = 0;
    return (*jul);
}

void    julia(t_fractol *f)
{
    int x;
    int y;
    int i;

    y = 0;
    while (y < HEI)
    {
        x = 0;
        while (x < WID)
        {
            f->j->Im = ((y - WID / 2 ) * f->j->scale) / HEI / 2 + f->j->zoomY;
            f->j->Re = ((x - WID / 2) * f->j->scale) / HEI / 2 + f->j->zoomX;

            i = countIter(f);
            if (i < f->j->maxIter)
                put_colour2img(&(f->image), x, y, i * 1555 , f);
            else
                put_colour2img(&(f->image), x, y, 0, f);
            x++;
        }
        y++;
    }

}