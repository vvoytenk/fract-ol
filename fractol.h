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

typedef struct  s_complex
{
    double Re;
    double Im;
    double cRe;
    double cIm;
    double temp;
    double scale;
    double zoomX;
    double zoomY;
    int     color;
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
    char rgb[4];
};

int    fractol(t_fractol *f);
int     usage(void);
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
int     expose(t_fractol  *f);
int     key_hook(int keycode);
t_complex   initial_fractal(t_complex *fract);
void    mandel(t_fractol *f);
int     get_color(int i, t_fractol *f, int var);
void    buddha(t_fractol *f);
void    newton(t_fractol *f);
int     countNewton(t_fractol *f);
void    ship(t_fractol *f);
int     countShip(t_fractol *f);
int     countBio(t_fractol *f);
void    biomorph(t_fractol *f);
void tricorn(t_fractol *f);
int     countTricorn(t_fractol *f);
void   fractheart(t_fractol *f);
int    countHeart(t_fractol *f);
int valid(char *name , t_fractol *f);

#endif
