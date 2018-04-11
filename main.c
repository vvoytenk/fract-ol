#include "fractol.h"

int     error()
{
    ft_putstr("USAGE:\n1 - Julia\n2 - Mandelbrot");
    return (0);
}

int     main(int argc, char **argv)
{
    if (argc != 2)
        return (error(1));
    fractol(argv[1]);
    return (0);
}