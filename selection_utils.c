/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsquarci <lsquarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:10:25 by lsquarci          #+#    #+#             */
/*   Updated: 2024/03/11 10:10:26 by lsquarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "utils.h"

void set_fractal_type(app_data *app, char *arg)
{
    if (!ft_strncmp(arg, "mandelbrot", 10))
        app->params.type = 'm';
    else if (!ft_strncmp(arg, "julia", 5))
        app->params.type = 'j';
    else if (!ft_strncmp(arg, "ship", 4))
        app->params.type = 's';
    else if (!ft_strncmp(arg, "phoenix", 7))
        app->params.type = 'p';
    else if (!ft_strncmp(arg, "remarkable", 10))
        print_remark();
    else
        print_error();
}

void set_julia_params(app_data *app, char *arg1, char *arg2)
{
    app->params.type = 'j';
    app->params.j_re = ft_atod(arg1);
    app->params.j_im = ft_atod(arg2);
}

void set_phoenix_params(app_data *app, char *arg1, char *arg2, char *arg3, char *arg4) {
    app->params.type = 'p';
    app->params.pc_re = ft_atod(arg1);
    app->params.pc_im = ft_atod(arg2);
    app->params.pk_re = ft_atod(arg3);
    app->params.pk_im = ft_atod(arg4);
}

