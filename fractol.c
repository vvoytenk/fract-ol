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
    if (f->numF == 4)
        newton(f);
    if (f->numF == 5)
        ship(f);
    if (f->numF == 6)
        biomorph(f);
    if (f->numF == 7)
        tricorn(f);
    if (f->numF == 8)
        fractheart(f);
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

int     countTricorn(t_fractol *f)
{
    int i;

    i = 0;
    while (f->j->Re * f->j->Re + f->j->Im * f->j->Im <= 4)
    {
        f->j->temp = f->j->Re * f->j->Re - f->j->Im * f->j->Im + f->j->cRe;
        f->j->Im = -2 * f->j->Re * f->j->Im + f->j->cIm;
        f->j->Re = f->j->temp;
        if (i > f->j->maxIter)
            break;
        i++;
    }
    return (i);
}

int     countBio(t_fractol *f)
{
    int i;
    double x;
    double y;

    i = 0;
    x = f->j->Re / 2;
    y = f->j->Im / 2;
    while (i <= f->j->maxIter)
    {
        f->j->Re = x * (x * x - 3 * y * y) * 2 + f->j->cRe;
        f->j->Im = y * (3 * x * x - y * y) * 2 + f->j->cIm;
        if (abs((int)f->j->Re) < 10 && abs((int)f->j->Im) < 10)
            return (get_color(f->j->maxIter, f, 1));
        if (abs((int)f->j->Re) >= 10 && abs((int)f->j->Im) < 10)
            return (get_color(f->j->maxIter / 256, f, 1));
        if (abs((int)f->j->Re) < 10 && abs((int)f->j->Im) >= 10)
            return (get_color(f->j->maxIter % 256, f, 1));
        if (abs((int)f->j->Re) >= 10 && abs((int)f->j->Im) >= 10)
            return (get_color(f->j->maxIter - 256, f, 1));
        if (f->j->Re * f->j->Re + f->j->Im * f->j->Im > 4)
            break;
        i++;
    }
    return (i);
}

int     countShip(t_fractol *f)
{
    int i;

    i = 0;
    while (f->j->Re * f->j->Re + f->j->Im * f->j->Im <= 4)
    {
        f->j->temp = f->j->Re * f->j->Re - f->j->Im * f->j->Im + f->j->cRe;
        f->j->Im = fabs(2 * f->j->Re * f->j->Im) + f->j->cIm;
        f->j->Re = f->j->temp;
        if (i > f->j->maxIter)
            break;
        i++;
    }
    return (i);
}

int    countHeart(t_fractol *f)
{
    int i;

    i = 0;
    while (f->j->Re * f->j->Re + f->j->Im * f->j->Im <= 4)
    {
        f->j->temp = f->j->Re * f->j->Re - f->j->Im * f->j->Im + f->j->cRe;
        f->j->Im = 2 * fabs(f->j->Re) * f->j->Im + f->j->cIm;
        f->j->Re = f->j->temp;
        if (i > f->j->maxIter)
            break;
        i++;
    }
    return (i);
}

int     countNewton(t_fractol *f)
{
    int i;
    double tempx;
    double tempy;

    i = 0;
    while (f->j->cRe * f->j->cRe + f->j->cIm * f->j->cIm <= 4)
    {
        tempx = f->j->cRe * f->j->cRe;
        tempy = f->j->cIm * f->j->cIm;
        f->j->Im = (tempx + tempy) * (tempx + tempy);
        f->j->cRe =  2 / 3 * f->j->cRe + (tempx - tempy) / (3 * f->j->Im);
        f->j->cIm =  2 / 3 * f->j->cIm * (1 - f->j->cRe / f->j->Im);
        if (i > f->j->maxIter)
            break;
        i++;
    }
    return (i);
}
