/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoytenk <vvoytenk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 16:46:33 by vvoytenk          #+#    #+#             */
/*   Updated: 2018/04/16 16:46:34 by vvoytenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void			create_image(t_fractol *f)
{
    f->mlx = mlx_init();
    f->win = mlx_new_window(f->mlx, WID, HEI, "Fract'ol");
    f->image.ptr = mlx_new_image(f->mlx, WID, HEI);
    f->image.data = mlx_get_data_addr(f->image.ptr,
			&f->image.bits_per_pixel, &f->image.size_line, &f->image.endian);
}

void			put_colour2img(t_image *img, double x, double y, int colour, t_fractol *f)
{
    if (x < 0 || y < 0 || x >= WID || y >= HEI)
        return ;
    *(int *)(img->data + ((int)x + (int)y * WID) * 4) = f->j.color;
}
