/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsquarci <lsquarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:09:41 by lsquarci          #+#    #+#             */
/*   Updated: 2024/03/11 12:43:49 by lsquarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	fractal_init(parameters *params)
{
	params->xshift = 0;
	params->yshift = 0;
	params->zoom = 1.0;
	params->iterations = 40;
	params->z0 = 0;
	params->j_re = 0.355534;
	params->j_im = -0.337292;
	params -> pc_re = 0.5666 ;
	params -> pc_im = 0.0;
	params -> pk_re = -0.5;
	params -> pk_im = 0.0;
}

void	system_init(app_data *app)
{
	app->mlx_data.mlx = mlx_init();
	app->mlx_data.mlx_win = mlx_new_window(app->mlx_data.mlx, 800, 600, \
			"Fractal explorer");
	app->mlx_data.img = mlx_new_image(app->mlx_data.mlx, 800, 600);
	app->mlx_data.addr = mlx_get_data_addr(app->mlx_data.img, \
			&app->mlx_data.bits_per_pixel, &app->mlx_data.line_length, \
			&app->mlx_data.endian);
	mlx_key_hook(app->mlx_data.mlx_win, &key_hook, app);
	mlx_mouse_hook(app->mlx_data.mlx_win, &mouse_scroll_hook, app);
	mlx_hook(app->mlx_data.mlx_win, 17, 1L << 0, &close_button_hook, \
			&(app->mlx_data));
}

void	ship_init(int *i, Complex *z, parameters *params)
{
	*i = 0;
	z->re = params-> z0;
	z->im = -params-> z0;
	return ;
}
