#include "fractol.h"

int     error(int code)
{
    if (code == 1)
        ft_putstr("ERROR: you must put ONE arg\n");
    if (code == 2)
        ft_putstr("ERROR: choose available fractols:\nJulia\nMandelbrot");
    return (0);
}

int     main(int argc, char **argv)
{
    if (argc != 2)
        return (error(1));
    fractol(argv[1]);
    return (0);
}