/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsquarci <lsquarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:09:07 by lsquarci          #+#    #+#             */
/*   Updated: 2024/03/11 12:43:05 by lsquarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	close_button_hook(void *param)
{
	t_data	*app;

	app = (t_data *)param;
	mlx_destroy_image(app->mlx, app->img);
	mlx_destroy_window(app->mlx, app->mlx_win);
	free(app->mlx);
	exit(0);
}

int	mouse_scroll_hook(int button, int x, int y, app_data *app)
{
	if (button == SCR_UP)
	{
		app->params.zoom *= 0.90;
	}
	else if (button == SCR_DOWN)
	{
		app->params.zoom /= 0.90;
	}
	draw_fractal(app);
	return (0);
}

static void	handle_shift(int keycode, parameters *params)
{
	float	shift_factor;

	shift_factor = 0.5 * params->zoom;
	if (keycode == LEFT)
		params->xshift -= shift_factor;
	if (keycode == RIGHT)
		params->xshift += shift_factor;
	if (keycode == UP)
		params->yshift += shift_factor;
	if (keycode == DOWN)
		params->yshift -= shift_factor;
}

int	key_hook(int keycode, app_data *app)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_image(app->mlx_data.mlx, app->mlx_data.img);
		mlx_destroy_window(app->mlx_data.mlx, app->mlx_data.mlx_win);
		free(app->mlx_data.mlx);
		exit(0);
	}
	if (keycode == PLUS_KEY)
		app->params.iterations += 10;
	if (keycode == MINUS_KEY)
		app->params.iterations -= 10;
	if (keycode == Z)
	{
		app->params.z0 += 0.1 * (app->params.zoom);
		app->params.yshift -= 0.1 * (app->params.zoom);
	}
	if (keycode == R)
		fractal_init(&(app->params));
	handle_shift(keycode, &(app->params));
	draw_fractal(app);
	return (0);
}
