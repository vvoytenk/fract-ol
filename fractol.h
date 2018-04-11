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
#define FRACTOL_H

# include "mlx.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <math.h>
# include <stdio.h>


#  define WID 1600
#  define HEI 1200


typedef struct  s_fract
{
    void        *mlx;
    void        *win;
    double      re;
    double      im;
}               t_fract;

typedef struct s_complex
{
    double x,y;
}               t_complex;

void    fractol(char *file);
int     error();
void	create_window(t_fract *fract);
void    julia();
void    mandel();


void juliaSet(int width,int height,t_complex c,double radius,int n, t_fract *fract);
t_complex mapPoint(int width,int height,double radius,int x,int y);
double mod(t_complex a);
t_complex sqr(t_complex a);
t_complex add(t_complex a,t_complex b);



#endif
