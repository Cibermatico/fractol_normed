/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsquarci <lsquarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:10:33 by lsquarci          #+#    #+#             */
/*   Updated: 2024/03/11 12:54:52 by lsquarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_linux/mlx.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ITERATION 42
#define W 800
#define H 600
#define BOUND 2
#define ESC_KEY 65307
#define PLUS_KEY 65451
#define MINUS_KEY 65453
#define RIGHT 65363
#define LEFT 65361
#define UP 65362
#define DOWN 65364
#define SCR_UP 4
#define SCR_DOWN 5
#define Z 122
#define R 114

typedef struct s_dtoa
{
	long long int	length;
	long long int	length2;
	long long int	i;
	long long int	n1;
	long long int	position;
	char			sign;
	float			n2;
}	t_dtoa;

typedef struct s_parameters
{
	char	type;
	int		iterations;
	double	zoom;
	double	xshift;
	double	yshift;
	double	offset;
	double	z0;
	double	j_re;
	double	j_im;
	double	pc_re;
	double	pc_im;
	double	pk_re;
	double	pk_im;
}	t_parameters;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_t_app
{
	t_parameters	params;
	t_data			mlx_data;
}	t_app;

typedef struct s_color_render
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_complex_nbr
{
	double	re;
	double	im;
}	t_compl;

typedef struct s_target_interval
{
	double	min;
	double	max;
}	t_i;

typedef struct s_aintseiya
{
	t_compl	z;
	t_compl	c;
	int		i;
}	t_phoenix;

t_compl			c_sum(t_compl z1, t_compl z2);
double			c_mod(t_compl z);
t_compl			c_sqr(t_compl z1);
t_compl			c_product(t_compl z1, t_compl z2);
t_compl			mandelbrot(t_compl z, t_compl c);
void			draw_fractal(t_app *app);
int				key_hook(int keycode, t_app *app);
int				close_button_hook(void *param);
int				mouse_scroll_hook(int button, int x, int y, t_app *app);
int				get_hexcolor(int red, int green, int blue);
void			fractal_init(t_parameters *params);
int				*julia_pixel_check(double x, double y, t_parameters *params);
int				ft_strncmp(char const *s1, char const *s2, size_t n);
int				*mdl_pixel_check(double x, double y, t_parameters *params);
int				*ship_pixel_check(double x, double y, t_parameters *params);
int				color_blender(int i, t_parameters *params);
int				*phoenix_pixel_check(double x, double y, t_parameters *params);
void			system_init(t_app *app);
double			ft_atod(char *s);
void			print_intro(void);
void			ft_putstr(char *str);
void			set_fractal_type(t_app *app, char *arg);
void			set_julia_params(t_app *app, char *arg1, char *arg2);
void			set_phoenix_params(t_app *app, char *args[]);
void			print_error(void);
void			draw_legend(t_data *mlx);
void			ship_init(int *i, t_compl *z, t_parameters *params);
int				mouse_motion_hook(int x, int y, t_app *app);
void			draw_image_to_window(void *mlx_ptr, void *win_ptr, \
			char *image_path);
int				dummy_mdl(t_app *app);
unsigned int	*color_mdl(int *i);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			ft_dtoa(float f, char r[], t_dtoa *context);
void			print_remark(void);
double			scaling2(double nbr, double old_min, \
		double old_max, t_i new_interval);
int				close_dummy_hook(t_app *app);
