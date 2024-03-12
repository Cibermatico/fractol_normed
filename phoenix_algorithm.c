/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoenix_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsquarci <lsquarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:10:15 by lsquarci          #+#    #+#             */
/*   Updated: 2024/03/11 12:49:27 by lsquarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	phoenix_init(t_phoenix *tp, double x, double y, t_parameters *pr)
{
	tp->i = 0;
	tp->z.re = scaling2(y, 0, W, (t_i){-2, 2}) * pr->zoom - pr->yshift + 0.87;
	tp->z.im = scaling2(x, 0, H, (t_i){2, -2}) * pr->zoom - pr->xshift + 0.65;
	tp->c.re = pr->pc_re;
	tp->c.im = pr->pc_im;
}

int	*phoenix_pixel_check(double x, double y, t_parameters *params)
{
	int			*output;
	t_phoenix	tp;
	t_compl		k;
	t_compl		tmp;
	t_compl		old;

	output = (int *)calloc(2, sizeof(int));
	phoenix_init(&tp, x, y, params);
	k.re = params->pk_re;
	k.im = params->pk_im;
	while (tp.i++ < params->iterations + 35)
	{
		tmp = tp.z;
		tp.z = c_sum(c_sqr(tp.z), c_sum(tp.c, c_product(k, old)));
		old = tmp;
		if (c_mod(tp.z) > 2)
		{
			output[0] = 0;
			output[1] = tp.i + 1 - (log(2) / c_mod(tp.z)) / log(2);
			return (output);
		}
	}
	output[0] = 1;
	return (output);
}
