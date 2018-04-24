/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoytenk <vvoytenk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 17:31:29 by vvoytenk          #+#    #+#             */
/*   Updated: 2018/04/10 17:31:30 by vvoytenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
#include <pthread.h>


#  define WID 1000
#  define HEI 800
#  define THREADS 8

typedef struct  s_complex
{
    double  cRe;
    double  cIm;
    double  nRe;
    double  nIm;
    double  oRe;
    double  oIm;
    double  zoom;
    double  moveX;
    double  moveY;
    double  maxRe;
    double  maxIm;
    double  minRe;
    double  minIm;
    double  mouse_x;
    double  mouse_y;
    double  mouseRe;
    double  mouseIm
    ;
    int     color;
    int     maxIter;
    int     x;
    int     y;
    int     i;

}               t_complex;

typedef struct	s_image
{
    void		*ptr;
    char		*data;
    int			bits_per_pixel;
    int			size_line;
    int			endian;
   // void        *img;
}				t_image;

typedef struct  s_fractol
{
    void        *mlx;
    void        *win;
    t_complex   j;
    t_image     image;
}               t_fractol;


typedef struct  s_multi
{
    int         i;
    t_fractol   arg[THREADS];
}               t_multi;

void    fractol(char *file, t_fractol *f);
int     error();
void    julia(t_fractol *fractol);
void    multijulia(t_fractol *f);
void    mandel(t_fractol *fractol);
t_complex   initial_julia(t_fractol *fractol);
t_complex     *initial_mandel(t_fractol *f);
void			create_image(t_fractol *f);
void			put_colour2img(t_image *img, double x, double y, int color, t_fractol *f);
int    mouse_julia(int x, int y, t_fractol *f);



#endif
