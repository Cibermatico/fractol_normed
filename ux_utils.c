/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ux_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsquarci <lsquarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:10:38 by lsquarci          #+#    #+#             */
/*   Updated: 2024/03/11 10:10:39 by lsquarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "utils.h"

void draw_legend(t_data *mlx)
{
    char *text0;
    char *text1;
    char *text2;
    char *text3;
    char *text4;

    text0 = "Mouse wheel: zoom";
    text1 = "Arrows: move";
    text2 = "+,-: iterations";
    text3 = "z: destroy/move up";
    text4 = "r: reset";
    mlx_string_put(mlx->mlx, mlx->mlx_win, 5, 12, 0xFFFFFF, text0);
    mlx_string_put(mlx->mlx, mlx->mlx_win, 5, 24, 0xFFFFFF, text1);
    mlx_string_put(mlx->mlx, mlx->mlx_win, 5, 36, 0xFFFFFF, text2);
    mlx_string_put(mlx->mlx, mlx->mlx_win, 5, 48, 0xFFFFFF, text3);
    mlx_string_put(mlx->mlx, mlx->mlx_win, 5, 60, 0xFFFFFF, text4);
}

void print_remark(void)
{
    ft_putstr("Stars:     ./fractol julia 0.4 0.4 \nDragon:    ./fractol julia -0.835 -0.2321 \nVortex:    ./fractol julia 0.355 0.355 \nFlame:     ./fractol phoenix -0.4 0.1 0.2955 0 \nButterfly: ./fractol phoenix 0.4 0 -0.25 0\nUnknown:   ./fractol phoenix 0.2 0.5 0.1 -0.2\nManowar:   ./fractol phoenix 0.01 0 1 0 \n");
exit(0);
}


void print_intro(void)
{
    ft_putstr("Welcome to fractal explorer!\nCommand list:\n./fractol mandelbrot: show classic Mandelbrot set.\n./fractol julia: show Julia set.\n./fractol julia [c_re] [c_im]: show Julia set associated with the point provided.\n./fractol ship: show Burning Ship Mandelbrot set.\n./fractol phoenix: show Phoenix Julia set.\n./fractol phoenix [c_re] [c_im] [k_re] [k_im]: show Phoenix Julia set associated with the points provided.\n./fractol julia_map: surprise!\n./fractol remarkable: parameters suggestion for remarkable fractals.\n");
exit(0);
}

void print_error()
{
    ft_putstr("Invalid parameters");
    ft_putstr("\n");
    exit(0);
}

