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
    printf("%d %d\n", x, y);
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

    f->j->scale *= 1.5;
    f->j->zoomX += ((x - HEI / 1.5) / WID / 2) / f->j->scale;
    f->j->zoomY += ((y - WID / 2) / HEI / 1.5) / f->j->scale;
}
void    zoomout(int x, int y, t_fractol *f)
{

    f->j->scale *= 0.9;
    f->j->zoomX += ((x - HEI / 1.5) / WID / 2) / f->j->scale;
    f->j->zoomY += ((y - WID/ 2 ) / HEI / 1.5) / f->j->scale;
}

int		mouse_move(int x, int y, t_fractol *f)
{
    if (f->j->flag)
    {
        f->j->cIm = ((double)x - WID / 2) / WID + 0.7;
        f->j->cRe = ((double)y - HEI / 2) / HEI + 0.2;
        expose(f);
    }
    return (0);
}

int     key_hook(int keycode)
{
    if (keycode == 53)
        exitX();
    return (0);
}
