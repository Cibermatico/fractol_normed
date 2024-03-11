/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsquarci <lsquarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:08:20 by lsquarci          #+#    #+#             */
/*   Updated: 2024/03/11 10:17:57 by lsquarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <printf.h>
#include "utils.h"

int	*julia_pixel_check(double x, double y, parameters *params)
{
	int		i;
	Complex	z;
	Complex	tmp;
	Complex	c;
	int		*output;

	output = (int *)calloc(2, sizeof(int));   
	i = 0;
	z.re = scaling(x, 0, WIDTH, -BOUND, BOUND)*params->zoom + params-> xshift;   
	z.im = scaling(y, 0, HEIGHT, BOUND, -BOUND)*params->zoom + params-> yshift;    
	c.re = params->j_re;
	c.im = params->j_im;    
	while (i < params->iterations + 65)
	{
		z = c_sum(c_sqr(z),c);
		if (c_mod(z) > 2)
		{
			output[0] = 0;
			output[1] = i + 1 -(log(2)/c_mod(z))/log(2)
			return output;
		}
		i++;
	}
	output[0] = 1;
	return (output);
}

int *mdl_pixel_check(double x, double y,parameters *params)
{
	int		i;
	Complex	z;
	Complex	tmp;
	Complex	c;
	int		*output;

	output = (int *)calloc(2, sizeof(int));
	i = 0;
	z.re = 0 + params->z0;
	z.im = 0 + params->z0;
	c.re = scaling(x, 0, WIDTH, -BOUND, BOUND)*params->zoom + params-> xshift;
	c.im = scaling(y, 0, HEIGHT, BOUND, -BOUND)*params->zoom + params-> yshift;
	while (i < params->iterations)
	{
		z = c_sum(c_sqr(z),c);
		if (c_mod(z) > 2)
		{
			output[0] = 0;
			output[1] =  i + 1 -(log(2)/c_mod(z))/log(2);
			return output;
		}
		i++;
	}
	output[0] = 1;
	return (output);
}

int *ship_pixel_check(double x, double y, parameters *params)
{
	int		i;
	Complex	z;
	Complex	c;
	int		*output; 
	double	tmp;
	
	output = (int *)calloc(2, sizeof(int));
	ship_init(&i, &z, params);
	c.re = scaling(x, 0, WIDTH, -2, 2) * params->zoom + params->xshift;
	c.im = scaling(600 - y, 0, 600, 2, -2) * params->zoom - params->yshift;
	while (i++ < params->iterations)
	{
		tmp = 2 * fabs(z.re) * fabs(z.im) + c.im;
		z.re = z.re * z.re - z.im * z.im + c.re;
		z.im = tmp;
		if (c_mod(z) > 2)
		{
			i = i + 1 -(log(2)/c_mod(z))/log(2);
			output[0] = 0;
			output[1] = i;
			return output;
		}
	}
	output[0] = 1;
	return output;
}
