/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoytenk <vvoytenk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 16:35:01 by vvoytenk          #+#    #+#             */
/*   Updated: 2018/05/15 16:35:03 by vvoytenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_hook(int keycode, int x, int y, t_fractol *f)
{
    if (x >= 0 && y >= 0 && x <= WID && y <= HEI)
    {
        if (keycode == 4)
            zoomin(x, y, f);
        else if (keycode == 5)
            zoomout(x, y, f);
    }
    expose(f);
    return (0);
}

void    zoomin(int x, int y, t_fractol *f)
{
    //double mouseshifty;
    f->j->cIm = f->j->maxIm - y * (f->j->maxIm - f->j->minIm) / HEI;
    f->j->cRe = f->j->minRe + x * (f->j->maxRe - f->j->minRe) / WID;
    if (f->j->cRe < 0)
        f->j->maxRe += f->j->scale;
    else if (f->j->cRe >= 0)
        f->j->minRe -= f->j->scale;
    if (f->j->cIm < 0)
        f->j->maxIm += f->j->scale;
    else if (f->j->cIm >= 0)
        f->j->minIm -= f->j->scale;
//    mouseshifty = ((y - HEI) / WID) * fr->zoom;
//
//    fr->shifty += fr->mouseshifty;
//    fr->mouseshiftx = ((x - 400.) / 800.) * fr->zoom;
//    fr->shiftx += fr->mouseshiftx;
//    fr->zoom /= 1.05;
//    fr->shiftx -= ((x - 400.) / 800.) * fr->zoom;
//    fr->shifty -= ((y - 400.) / 800.) * fr->zoom;
}
void    zoomout(int x, int y, t_fractol *f)
{
    f->j->cIm = f->j->maxIm - y * (f->j->maxIm - f->j->minIm) / HEI;
    f->j->cRe = f->j->minRe + x * (f->j->maxRe - f->j->minRe) / WID;
    if (f->j->cRe < 0)
        f->j->maxRe -= f->j->scale;
    else if ( f->j->cRe >= 0)
        f->j->minRe += f->j->scale;
    if (f->j->cIm < 0)
        f->j->maxIm -= f->j->scale;
    else if (f->j->cIm >= 0)
        f->j->minIm += f->j->scale;
}

int		mouse_move(int x, int y, t_fractol *f)
{
    if (f->j->flag)
    {
        f->j->cIm = f->j->maxIm - y * (f->j->maxIm - f->j->minIm) / HEI;
        f->j->cRe = f->j->minRe + x * (f->j->maxRe - f->j->minRe) / WID;
        expose(f);
    }
    return (0);
}

int     key_hook(int keycode, t_fractol *f)
{
    if (keycode == 53)
        exitX();
    return (0);
}
