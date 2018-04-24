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

void    fractol(char *file, t_fractol *f)
{
    f = (t_fractol *)malloc(sizeof(t_fractol));
    create_image(f);
    if (file[0] == '1')
    {
        multijulia(f);
        mlx_hook(f->win, 6, 1L, mouse_julia, f);
      //  mlx_mouse_hook(f->win, mouse_julia, f);
    }
//   if (file[0] == '2')
//        mandel(f);
    else
        error();
}
