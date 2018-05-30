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

void    mandel(t_fractol *f)
{
    int x;
    int y;
    int i;

    f->j->flag = 0;
    x = 0;
    while (x < WID)
    {
        f->j->cRe = ((x - WID / 1.5) * f->j->scale) / HEI / 1.5 + f->j->zoomX;
        y = 0;
        while (y < HEI)
        {
            f->j->cIm = ((y - WID / 2) * f->j->scale) / HEI / 1.5 + f->j->zoomY;
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

void tricorn(t_fractol *f)
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
            i = countTricorn(f);
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

void   fractheart(t_fractol *f)
{
    int x;
    int y;
    int i;

    y = 0;
    while (y < HEI)
    {
        f->j->cIm = ((y - WID / 2 ) * f->j->scale) / HEI / 1.5 + f->j->zoomY;
        x = 0;
        while (x < WID)
        {
            f->j->cRe = ((x - WID / 1.5) * f->j->scale) / HEI / 1.5 + f->j->zoomX;
            f->j->Im = f->j->cIm;
            f->j->Re = f->j->cRe;
            i = countHeart(f);
            if (i < f->j->maxIter)
                put_colour2img(&(f->image), (double)x, (double)y, get_color(i + 255, f, 255), f);
            else
                put_colour2img(&(f->image), (double)x, (double)y, 0xffcccc, f);
            x++;
        }
        y++;
    }
}

void    biomorph(t_fractol *f)
{
    int x;
    int y;
    int i;
    double ymax = 5.4;
    double ymin = -ymax;
    double xmax = ymax * WID / HEI;
    double xmin = -xmax;

    y = 0;
    while (y < HEI)
    {
        x = 0;
        while (x < WID)
        {
            f->j->cRe = ((y - WID / 1.5) * f->j->scale) / HEI / 1.5 + f->j->zoomY;
            f->j->cIm = ((x - WID / 2) * f->j->scale) / HEI / 1.5 + f->j->zoomX;
            f->j->Re = xmin + (xmax - xmin) * x / (HEI - 1);
            f->j->Im = -ymin - (ymax - ymin) * y / (WID - 1);
            i = countBio(f);
            if (abs((int) f->j->Re) < 10 || abs((int) f->j->Im) < 10)
                put_colour2img(&(f->image), (double)x, (double)y, get_color(0xff0000 + i , f, 1), f);
            else
                put_colour2img(&(f->image), (double)x, (double)y, 0, f);
            x++;
        }
        y++;
    }
}

void    newton(t_fractol *f)
{
    int x;
    int y;
    int i;

    y = 0;
    while (y < HEI)
    {
        x = 0;
        while(x < WID)
        {
            f->j->cIm = ((y - WID / 1.5 ) * f->j->scale) / HEI / 1.5 + f->j->zoomY;
            f->j->cRe = ((x - WID / 2) * f->j->scale) / HEI / 1.5 + f->j->zoomX;
            i = countNewton(f);
            if (i < f->j->maxIter)
                put_colour2img(&(f->image), (double)y, (double)x, i * 1555, f);
            else
                put_colour2img(&(f->image), (double)y, (double)x, 0, f);
            x++;
        }
        y++;
    }
}

void    ship(t_fractol *f)
{
    int x;
    int y;
    int i;

    y = 0;
    while (y < HEI)
    {
        f->j->cIm = ((y - WID / 1.5 ) * f->j->scale) / HEI / 1.5 + f->j->zoomY;
        x = 0;
        while (x < WID)
        {
            f->j->cRe = ((x - WID / 2) * f->j->scale) / HEI / 1.5 + f->j->zoomX;
            f->j->Im = f->j->cIm;
            f->j->Re = f->j->cRe;
            i = countShip(f);
            if (i < f->j->maxIter)
                put_colour2img(&(f->image), (double)x, (double)y, i * 1600, f);
            else
                put_colour2img(&(f->image), (double)x, (double)y, 0, f);
            x++;
        }
        y++;
    }
}

