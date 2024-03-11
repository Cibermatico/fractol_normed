/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dummy_utils_coord.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsquarci <lsquarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:08:56 by lsquarci          #+#    #+#             */
/*   Updated: 2024/03/11 10:26:07 by lsquarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "utils.h"

void draw_image_to_window(void *mlx_ptr, void *win_ptr, char *image_path)
{
	int img_width;
	int img_height;
	void *image_ptr = mlx_xpm_file_to_image(mlx_ptr, image_path,  &img_width, &img_height);
	if (!image_ptr)
	{
		printf("Errore: impossibile caricare l'immagine.\n");
		return;
	}
	mlx_put_image_to_window(mlx_ptr, win_ptr, image_ptr,  0, 0);
	mlx_destroy_image(mlx_ptr, image_ptr);
}

int	key_hook_dummy(int keycode, app_data *app)
{   
	if (keycode == ESC_KEY) /*il free non serve*/
	{
		mlx_destroy_image(app->mlx_data.mlx, app->mlx_data.img);       
		mlx_destroy_window(app->mlx_data.mlx, app->mlx_data.mlx_win);
		free(app->mlx_data.mlx);       
		exit(0);
	}    
	if(keycode == PLUS_KEY)	
		app->params.iterations += 10;   	
	if(keycode == MINUS_KEY)	    
		app->params.iterations -= 10;  
	draw_fractal(app); 	
return (0);
}

int close_dummy_hook(app_data *app) 
{
	mlx_destroy_image(app->mlx_data.mlx, app->mlx_data.img);       
	mlx_destroy_window(app->mlx_data.mlx, app->mlx_data.mlx_win);
	free(app->mlx_data.mlx);       
	exit(0);
}

int	mouse_motion_hook(int x, int y, app_data *app)
{
	if (app->params.type == 'j')
	{
		app->params.j_re = scaling(x, 0, WIDTH/2, -BOUND, BOUND)* 0.81 * \
							app->params.zoom + (app->params.xshift-0.5);
		app->params.j_im = scaling(y, 0, HEIGHT/2, BOUND, -BOUND)* 0.81 * \
							app->params.zoom + (app->params.yshift-0.405);
	}
	draw_fractal(app);
	return 0;
}

int dummy_mdl(app_data *app)
{
	void    *mlx_ptr;
	void    *win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 330, 220, "Mandelbrot Set");    
	draw_image_to_window(mlx_ptr, win_ptr, "mdl_resized.xpm");
	mlx_hook(win_ptr, 6, 1L<<6, &mouse_motion_hook, app);
	mlx_key_hook(win_ptr, &key_hook_dummy, app);
	mlx_hook(win_ptr, 17, 1L<<0, &close_dummy_hook, app);
	mlx_loop(mlx_ptr);
}




