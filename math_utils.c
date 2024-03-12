/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsquarci <lsquarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:10:01 by lsquarci          #+#    #+#             */
/*   Updated: 2024/03/11 12:44:06 by lsquarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_compl	c_sum(t_compl z1, t_compl z2)
{
	t_compl	res;

	res.re = z1.re + z2.re;
	res.im = z1.im + z2.im;
	return (res);
}

double	c_mod(t_compl z)
{
	return (sqrt(z.re * z.re + z.im * z.im));
}

t_compl	c_sqr(t_compl z1)
{
	t_compl	res;

	res.re = (z1.re * z1.re) - (z1.im * z1.im);
	res.im = (2 * z1.im * z1.re);
	return (res);
}

t_compl	c_product(t_compl z1, t_compl z2)
{
	t_compl	res;

	res.re = (z1.re * z2.re) - (z1.im * z2.im);
	res.im = (z1.re * z2.im) + (z1.im * z2.re);
	return (res);
}

double	scaling2(double nbr, double old_min, double old_max, t_i new_interval)
{
	return ((new_interval.max - new_interval.min) * \
			((nbr - old_min) / (old_max - old_min)) + new_interval.min);
}
