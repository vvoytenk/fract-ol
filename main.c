/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoytenk <vvoytenk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 16:35:18 by vvoytenk          #+#    #+#             */
/*   Updated: 2018/05/15 16:35:23 by vvoytenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int     error()
{
    ft_putstr("USAGE:\n1 - Julia\n2 - Mandelbrot");
    return (0);
}

int     exitX()
{
    exit(1);
}

int     expose(t_fractol  *f)
{
    fractol(f);
    return (0);
}

int validation(char *name, t_fractol *f)
{
    if ((ft_strcmp(name, "Julia")) == 0)
    {
        f->j = (t_complex *)malloc(sizeof(t_complex));
        *f->j = initial_julia(f->j);
        f->numF = 1;
    }
    else if ((ft_strcmp(name, "Mandelbrot")) == 0)
    {
        f->j = (t_complex *)malloc(sizeof(t_complex));
        *f->j = initial_fractal(f->j);
        f->numF = 2;
    }
    else if((ft_strcmp(name, "Buddhabrot")) == 0)
    {
        f->j = (t_complex *)malloc(sizeof(t_complex));
        *f->j = initial_fractal(f->j);
        f->numF = 3;
    }
    else
        return (0);
    return (1);
}

int     main(int argc, char **argv)
{
    t_fractol f;

    if (argc != 2 || !validation(argv[1], &f))
        return (error());
    init_image(&f);
    fractol(&f);
    mlx_expose_hook(f.win, expose, &f);
    mlx_hook(f.win, 4, 6, mouse_hook, &f);
    mlx_hook(f.win, 6, 8, mouse_move, &f);
    mlx_hook(f.win, 2, 3, key_hook, &f);
    mlx_hook(f.win, 17, 0, exitX, 0);
    mlx_loop(f.mlx);
    return (0);
}
