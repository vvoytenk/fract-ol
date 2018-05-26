/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoytenk <vvoytenk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 18:08:13 by vvoytenk          #+#    #+#             */
/*   Updated: 2018/05/15 18:08:16 by vvoytenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
//#inlcude <>

t_complex   initial_fractal(t_complex *fract)
{
    fract->cRe = 0;
    fract->cIm = 0;
    fract->maxIter = 30;
    fract->scale = 5;
    fract->zoomX = 0;
    fract->zoomY = 0;
    fract->color = 1256855;
    fract->flag = 0;
    return (*fract);
}


void    mandel(t_fractol *f)
{
    int x;
    int y;
    int i;

    x = 0;
    while (x < WID)
    {
        f->j->cRe = ((x - WID / 1.5) * f->j->scale) / HEI / 1.5 + f->j->zoomX;
        y = 0;
        while (y < HEI)
        {
            f->j->cIm = ((y - WID / 2 ) * f->j->scale) / HEI / 1.5 + f->j->zoomY;
            f->j->Im = f->j->cIm;
            f->j->Re = f->j->cRe;
            i = countIter(f);
            if (i < f->j->maxIter)
                put_colour2img(&(f->image), (double)x, (double)y, i * 1555, f);
            else
                put_colour2img(&(f->image), (double)x, (double)y, 0, f);
            y++;
        }
        x++;
    }
}

void    buddha(t_fractol *f)
{
    int x;
    int y;
    int i;

    y = 0;
    while (y < HEI)
    {
        f->j->cRe = ((y - WID / 1.5 ) * f->j->scale) / HEI / 1.5 + f->j->zoomY;
        x = 0;
        while (x < WID)
        {
            f->j->cIm = ((x - WID / 2) * f->j->scale) / HEI / 1.5 + f->j->zoomX;
            f->j->Im = f->j->cIm;
            f->j->Re = f->j->cRe;
            i = countIter(f);
            if (i < f->j->maxIter)
                put_colour2img(&(f->image), (double)x, (double)y, get_color(i, f, 1), f);
            else
                put_colour2img(&(f->image), (double)x, (double)y, get_color(i, f, i/256), f);
            x++;
        }
        y++;
    }
}

int     get_color(int i, t_fractol *f, int delta)
{
    union u_rgb color;

    color.rgb[0] = f->j->color * cos(i) / delta * 1555;
    color.rgb[1] = f->j->color / cos(i) / delta * 1555;
    color.rgb[2] = f->j->color * sin(i * 2) / delta *1555;
    color.rgb[3] = 0;
    return (color.color);
}

