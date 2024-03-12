/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ux_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsquarci <lsquarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:10:38 by lsquarci          #+#    #+#             */
/*   Updated: 2024/03/11 12:50:46 by lsquarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	draw_legend(t_data *mlx)
{
	char	*text0;
	char	*text1;
	char	*text2;
	char	*text3;
	char	*text4;

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

void	print_remark(void)
{
	ft_putstr("Stars:     ./fractol julia 0.4 0.4 \n");
	ft_putstr("Dragon:    ./fractol julia -0.835 -0.2321 \n");
	ft_putstr("Vortex:    ./fractol julia 0.355 0.355 \n");
	ft_putstr("Flame:     ./fractol phoenix -0.4 0.1 0.2955 0 \n");
	ft_putstr("Butterfly: ./fractol phoenix 0.4 0 -0.25 0\n");
	ft_putstr("Unknown:   ./fractol phoenix 0.2 0.5 0.1 -0.2\n");
	ft_putstr("Manowar:   ./fractol phoenix 0.01 0 1 0 \n");
	exit(0);
}

void	print_intro(void)
{
	ft_putstr("Welcome to fractal explorer!\n");
	ft_putstr("Command list:\n");
	ft_putstr("./fractol mandelbrot: show classic Mandelbrot set.\n");
	ft_putstr("./fractol julia: show Julia set.\n");
	ft_putstr("./fractol julia [c_re] [c_im]: show Julia set ");
	ft_putstr("associated with the point provided.\n");
	ft_putstr("./fractol ship: show Burning Ship Mandelbrot set.\n");
	ft_putstr("./fractol phoenix: show Phoenix Julia set.\n");
	ft_putstr("./fractol phoenix [c_re] [c_im] [k_re] [k_im]:");
	ft_putstr("show Phoenix Julia set associated with the points provided.\n");
	ft_putstr("./fractol julia_map: surprise!\n");
	ft_putstr("./fractol remarkable: suggestion for remarkable fractals.\n");
	exit(0);
}

void	print_error(void)
{
	ft_putstr("Invalid t_parameters");
	ft_putstr("\n");
	exit(0);
}
