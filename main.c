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

int     exitX()
{
    exit(1);
}

int     expose(t_fractol  *f)
{
    fractol(f);
    return (0);
}

int     main(int argc, char **argv)
{
    t_fractol f;

    if (argc != 2 || !validation(argv[1], &f))
        return (usage());
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
