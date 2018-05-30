/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoytenk <vvoytenk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 21:35:35 by vvoytenk          #+#    #+#             */
/*   Updated: 2018/05/30 21:35:37 by vvoytenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int validation(char *name, t_fractol *f)
{
    if ((ft_strcmp(name, "Julia")) == 0)
    {
        f->j = (t_complex *)malloc(sizeof(t_complex));
        *f->j = initial_julia(f->j);
        f->numF = 1;
    }
    else if (!valid(name, f))
        return (0);
    return (1);

}

int valid(char *name , t_fractol *f)
{
    if ((ft_strcmp(name, "Mandelbrot")) == 0)
        f->numF = 2;
    else if((ft_strcmp(name, "Buddhabrot")) == 0)
        f->numF = 3;
    else if ((ft_strcmp(name, "Newton")) == 0)
        f->numF = 4;
    else if ((ft_strcmp(name, "BurningShip")) == 0)
        f->numF = 5;
    else if ((ft_strcmp(name, "Biomorph")) == 0)
        f->numF = 6;
    else if ((ft_strcmp(name, "Tricorn")) == 0)
        f->numF = 7;
    else if ((ft_strcmp(name, "Heart")) == 0)
        f->numF = 8;
    else
        return (0);
    f->j = (t_complex *)malloc(sizeof(t_complex));
    *f->j = initial_fractal(f->j);
    return (1);
}

int     usage(void)
{
    ft_putstr("<USAGE>\nCHOOSE FRACTAL:\n\nJulia\nMandelbrot"
                      "\nBurningShip\nTricorn\nHeart\nBuddhabrot"
                      "\nNewton\nBiomorph");
    return (0);
}

