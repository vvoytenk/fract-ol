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
    jul->minRe = -1.5;
    jul->minIm = -1.5;
    jul->maxIm = 1.5;
    jul->maxRe = 1.5;
    jul->cRe = 0;
    jul->cIm = 0;
    jul->maxIter = 30;
    jul->scale = 0.25;
    jul->flag = 1;
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
            f->j->Re = f->j->minRe + x * (f->j->maxRe - f->j->minRe) / WID;
            f->j->Im = f->j->maxIm - y * (f->j->maxIm - f->j->minIm) / HEI;
            i = countIter(f);
            if (i < f->j->maxIter)
                put_colour2img(&(f->image), x, y, get_color_buddha(i) , f);
            else
                put_colour2img(&(f->image), x, y, 0, f);
            x++;
        }
        y++;
    }

}