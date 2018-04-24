#include "fractol.h"

int     error()
{
    ft_putstr("USAGE:\n1 - Julia\n2 - Mandelbrot");
    return (0);
}

int     main(int argc, char **argv)
{
    t_fractol *f;

    if (!(f = (t_fractol *)malloc(sizeof(t_fractol))))
        return (0);
    if (argc != 2)
        return (error());
    fractol(argv[1], f);
    return (0);
}