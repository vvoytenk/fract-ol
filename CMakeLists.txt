cmake_minimum_required(VERSION 3.9)
project(fractol)

set(CMAKE_C_STANDARD 99)

#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror")

include_directories(inc libft/includes minilibx)

link_directories(libft minilibx)


set(SOURCE_FILES main.c fractol.h fractol.c julia.c draw.c hooks.c fractols.c)

add_executable(fractol ${SOURCE_FILES})


target_link_libraries(fractol -lft -lmlx "-framework OpenGL" "-framework AppKit")


#-l mlx -framework OpenGL -framework AppKit