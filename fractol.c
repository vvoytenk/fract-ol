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

void    fractol(char *file)
{
    if (ft_strcmp(file, "1") == 0)
        julia();
    else if (ft_strcmp(file, "2") == 0)
        mandel();
    else
        error();
}

void    julia()
{
    t_fract fract;
    double  cRe;
    double  cIm;
    double  nRe;
    double  nIm;
    double  oRe;
    double  oIm;
    double  zoom;
    double  moveX;
    double  moveY;
    int     color;
    int     maxIter;
    int     x;
    int     y;
    int     i;

    maxIter = 300;
    y = -1;
    zoom = 1;
    moveX = 0;
    moveY = 0;
    cRe = -0.7;
    cIm = 0.27015;
    color = 0;
    create_window(&fract);
    while (++y < HEI)
    {
        x = -1;
        while (++x < WID)
        {
            nRe = 1.5 * (x - WID / 2) / (0.5 * zoom * WID) + moveX;
            nIm = (y - HEI / 2) / (0.5 * zoom * HEI) + moveY;
            i = -1;
            while (++i < maxIter)
            {
                oIm = nIm;
                oRe = nRe;
                nRe = oRe * oRe - oIm * oIm + cRe;
                nIm = 2 * oRe * oIm + cIm;
                if ((nRe * nRe + nIm * nIm) > 4)
                    break ;
            }
            color = i * 500;
            mlx_pixel_put(fract.mlx, fract.win, x, y, color);
        }
    }


    mlx_loop(fract.mlx);
}

void    mandel()
{
    t_fract fract;
    double pRe;
    double pIm;
    double nRe;
    double nIm;
    double oRe;
    double oIm;
    double zoom = 1;
    double moveX = -0.5;
    double moveY = 0;
    int    color;
    int     maxIter = 300;
    int     x;
    int     y = -1;
    int i;

    create_window(&fract);
    while (++y < HEI)
    {
        x = -1;
        while (++x < WID)
        {
            pRe = 1.5 * (x - WID / 2) / (0.5 * zoom * WID) + moveX;
            pIm = (y - HEI / 2) / (0.5 * zoom * HEI) + moveY;
            nRe = nIm = 0;
            i = -1;
            while (++i < maxIter)
            {
                oRe = nRe;
                oIm = nIm;
                nRe = oRe * oRe - oIm *oIm +pRe;
                nIm = 2 * oRe * oIm +pIm;
                if ((nRe * nRe + nIm *nIm) > 4)
                    break ;
            }
            color = i * 1000;
            mlx_pixel_put(fract.mlx, fract.win, x, y, color);
        }
    }
    mlx_loop(fract.mlx);
}
