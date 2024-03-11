/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsquarci <lsquarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 13:59:45 by lsquarci          #+#    #+#             */
/*   Updated: 2024/03/11 12:43:54 by lsquarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include "utils.h"

void	process_pixel(app_data *app, int x, int y)
{
	int			*test;
	parameters	*params;
	t_data		*mlx;

	params = &(app->params);
	mlx = &(app->mlx_data);
	if (params->type == 'm')
		test = mdl_pixel_check(x, y, params);
	else if (params->type == 'j')
		test = julia_pixel_check(x, y, params);
	else if (params->type == 's')
		test = ship_pixel_check(x, y, params);
	else if (params->type == 'p')
		test = phoenix_pixel_check(x, y, params);
	if (test[0] == 1)
		my_mlx_pixel_put(mlx, x, y, get_hexcolor(0, 10, 30));
	if (test[0] == 0)
		my_mlx_pixel_put(mlx, x, y, color_blender(test[1], params));
	free(test);
}

void	draw_fractal(app_data *app)
{
	int		y;
	int		x;
	t_data	*mlx;

	y = 0;
	x = 0;
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			process_pixel(app, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	mlx = &(app->mlx_data);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 0, 0);
	draw_legend(mlx);
}

int	main(int argc, char *argv[])
{
	app_data	app;

	if (argc == 1)
		print_intro();
	system_init(&app);
	fractal_init(&(app.params));
	if (argc == 2)
		set_fractal_type(&app, argv[1]);
	else if (argc == 4 && !ft_strncmp(argv[1], "julia", 5))
		set_julia_params(&app, argv[2], argv[3]);
	else if (argc == 6 && !ft_strncmp(argv[1], "phoenix", 7))
		set_phoenix_params(&app, argv[2], argv[3], argv[4], argv[5]);
	else
		print_error();
	draw_fractal(&app);
	if (argc == 2 && !ft_strncmp(argv[1], "julia_map", 9))
		dummy_mdl(&app);
	mlx_loop(app.mlx_data.mlx);
}
