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
#  define HEI 1000
#  define THREADS 8
#  define PI 3.14159265359

typedef struct  s_complex
{
    double maxRe;
    double minRe;
    double maxIm;
    double minIm;
    double Re;
    double Im;
    double cRe;
    double cIm;
    double temp;
    double scale;
    int     maxIter;
    int flag;
}               t_complex;

typedef struct	s_image
{
    void		*ptr;
    char		*data;
    int			bits_per_pixel;
    int			size_line;
    int			endian;
}				t_image;

typedef struct  s_fractol
{
    void        *mlx;
    void        *win;
    t_complex   *j;
    t_image     image;
    int        numF;
}               t_fractol;

union u_rgb
{
    unsigned int color;
    char r;
    char g;
    char b;
    char zero;
};

int    fractol(t_fractol *f);
int     error();
int     exitX();
void    julia(t_fractol *fractol);
t_complex   initial_julia(t_complex *jul);
void			create_image(t_fractol *f);
void			init_image(t_fractol *f);
void			put_colour2img(t_image *img, double x, double y, int color, t_fractol *f);
int		mouse_hook(int keycode, int x, int y, t_fractol *f);
void    zoomout(int x, int y, t_fractol *f);
void    zoomin(int x, int y, t_fractol *f);
int		mouse_move(int x, int y, t_fractol *f);
int validation(char *name, t_fractol *f);
int     countIter(t_fractol *f);
int     expose(t_fractol  *f);int     key_hook(int keycode, t_fractol *f);
t_complex   initial_fractal(t_complex *fract);
void    mandel(t_fractol *f);
int     get_color_buddha(int i);
void    buddha(t_fractol *f);


#endif
