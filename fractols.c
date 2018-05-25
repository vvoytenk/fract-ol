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
    fract->minRe = -2;
    fract->minIm = -1.2;
    fract->maxRe = 0.5;
    fract->maxIm =  1.2;
    fract->cRe = 0;
    fract->cIm = 0;
    fract->maxIter = 10;
    fract->scale = 0.25;
    printf("%f", fract->scale);
    fract->flag = 0;
    return (*fract);
}


void    mandel(t_fractol *f)
{
    int x;
    int y;
    int i;

    y = 0;
    while (y < HEI)
    {
        f->j->cIm = f->j->maxIm - y * (f->j->maxIm - f->j->minIm) / HEI;
        x = 0;
        f->j->Im = f->j->cIm;
        while (x < WID)
        {
            f->j->cRe = f->j->minRe + x * (f->j->maxRe - f->j->minRe) / WID;
            f->j->Im = f->j->cIm;
            f->j->Re = f->j->cRe;
            i = countIter(f);
            if (i < f->j->maxIter)
                put_colour2img(&(f->image), (double)x, (double)y, i*1555, f);
            else
                put_colour2img(&(f->image), (double)x, (double)y, 0, f);
            x++;
        }
        y++;
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
        f->j->cIm = f->j->maxIm - y * (f->j->maxIm - f->j->minIm) / HEI;
        x = 0;
        f->j->Im = f->j->cIm;
        while (x < WID)
        {
            f->j->cRe = f->j->minRe + x * (f->j->maxRe - f->j->minRe) / WID;
            f->j->Im = f->j->cIm;
            f->j->Re = f->j->cRe;
            i = countIter(f);
            if (i < f->j->maxIter)
                put_colour2img(&(f->image), (double)y, (double)x, get_color_buddha(i), f);
            else
                put_colour2img(&(f->image), (double)y, (double)x, 0, f);
            x++;
        }
        y++;
    }
}

int     get_color_buddha(int i)
{
    union u_rgb color;

    color.r = (char) (cos(i));
    color.g = (char) (cos(i / 256 ));
    color.b = (char) (sin(i / 256));
    color.zero = 0;
    return (color.color);
}