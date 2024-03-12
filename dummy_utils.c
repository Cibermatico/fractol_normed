/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dummy_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsquarci <lsquarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:09:00 by lsquarci          #+#    #+#             */
/*   Updated: 2024/03/11 12:42:56 by lsquarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	draw_image_to_window(void *mlx_ptr, void *win_ptr, char *image_path)
{
	int		img_width;
	int		img_height;
	void	*image_ptr;

	image_ptr = mlx_xpm_file_to_image(mlx_ptr, image_path, &img_width, \
			&img_height);
	if (!image_ptr)
	{
		ft_putstr("Errore: impossibile caricare l'immagine.\n");
		free(image_ptr);
		free(mlx_ptr);
		exit(0);
	}
	mlx_put_image_to_window(mlx_ptr, win_ptr, image_ptr, 0, 0);
	mlx_destroy_image(mlx_ptr, image_ptr);
}

int	key_hook_dummy(int keycode, t_app *app)
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
	draw_fractal(app);
	return (0);
}

static void	print_coord(char *xcoord, char *ycoord)
{
	ft_putstr(xcoord);
	ft_putstr(" ");
	ft_putstr(ycoord);
	ft_putstr("\n");
}

int	mouse_motion_hook(int x, int y, t_app *app)
{
	char		xcoord[20];
	char		ycoord[20];
	void		*mlx_ptr;
	void		*win_ptr;
	t_dtoa		stupidnorm;

	win_ptr = app->mlx_data.mlx_win;
	mlx_ptr = app->mlx_data.mlx;
	if (app->params.type == 'j')
	{
		app->params.j_re = scaling2(x, 0, W / 2, (t_i){-2, 2}) * 0.81 * \
			app->params.zoom + (app->params.xshift - 0.5);
		app->params.j_im = scaling2(y, 0, H / 2, (t_i){2, -2}) * 0.81 * \
			app->params.zoom + (app->params.yshift - 0.405);
	}
	ft_dtoa((float)app->params.j_re, xcoord, &stupidnorm);
	ft_dtoa((float)app->params.j_im, ycoord, &stupidnorm);
	mlx_string_put(mlx_ptr, win_ptr, 693, 12, 0x000000, "Re(c):");
	mlx_string_put(mlx_ptr, win_ptr, 745, 12, 0x000000, xcoord);
	mlx_string_put(mlx_ptr, win_ptr, 693, 26, 0x000000, "Im(c):");
	mlx_string_put(mlx_ptr, win_ptr, 745, 26, 0x000000, ycoord);
	draw_fractal(app);
	print_coord(xcoord, ycoord);
	return (0);
}

int	dummy_mdl(t_app *app)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 330, 220, "Mandelbrot Set");
	draw_image_to_window(mlx_ptr, win_ptr, "mdl_resized.xpm");
	mlx_hook(win_ptr, 6, 1L << 6, &mouse_motion_hook, app);
	mlx_key_hook(win_ptr, &key_hook_dummy, app);
	mlx_hook(win_ptr, 17, 1L << 0, &close_dummy_hook, app);
	mlx_loop(mlx_ptr);
}
