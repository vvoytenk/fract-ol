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

t_complex   initial_julia(t_fractol *fractol)
{
    t_complex   jul;

    jul.maxIter = 300;
    jul.y = -1;
    jul.zoom = 1;
    jul.moveX = 0;
    jul.moveY = 0;
    jul.cRe = -0.7269;
    jul.cIm = 0.1889;

    return (jul);
}

void    julia(t_fractol *f)
{
    f->j = initial_julia(f);
    while (++(f->j.y) < HEI)
    {
        f->j.x = -1;
        while (++(f->j.x) < WID)
        {
            f->j.nRe = 1.5 * (f->j.x - WID / 2) / (0.5 * f->j.zoom * WID) + f->j.moveX;
            f->j.nIm = (f->j.y - HEI / 2) / (0.5 * f->j.zoom * HEI) + f->j.moveY;
            f->j.i = -1;
            while (++(f->j.i) < f->j.maxIter)
            {
                f->j.oIm = f->j.nIm;
                f->j.oRe = f->j.nRe;
                f->j.nRe = f->j.oRe * f->j.oRe - f->j.oIm * f->j.oIm + f->j.cRe;
                f->j.nIm = 2 * f->j.oRe * f->j.oIm + f->j.cIm;
                if ((f->j.nRe * f->j.nRe + f->j.nIm * f->j.nIm) > 4)
                    break ;
            }
            f->j.color = f->j.i;
            put_colour2img(&(f->image), f->j.x, f->j.y, f->j.color, f);
        }
    }
}

void    multijulia(t_fractol *f)
{
    t_multi *multi;
    pthread_t   th[THREADS];


    multi = (t_multi *)malloc(sizeof(t_multi) * THREADS);
    multi->i = -1;
    while (++multi->i < THREADS)
    {
        ft_memcpy(&multi->arg[multi->i], f, sizeof(t_fractol));
        pthread_create(&th[multi->i], NULL, (void *)julia, &multi->arg[multi->i]);
    }
    while (multi->i--)
        pthread_join(th[multi->i], NULL);
    mlx_hook(f->win, 6, 1L, mouse_julia, f);
    mlx_put_image_to_window(f->mlx, f->win, f->image.ptr, 0, 0);
    mlx_destroy_image(f->mlx, f->image.ptr);
    mlx_loop(f->mlx);
}

int    mouse_julia(int x, int y, t_fractol *f)
{
    if ((x >= 0 && y >= 0) && (x <= WID && y <= HEI))
    {
        f->j.cIm *= 0.04;
        f->j.cRe *= 0.04;
    }

    multijulia(f);
}
