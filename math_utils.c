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

Complex c_sum(Complex z1, Complex z2)
{
	Complex	res;
	
	res.re = z1.re + z2.re;
	res.im = z1.im + z2.im;
	return (res);
}


double	c_mod(Complex z)
{
	return (sqrt(z.re * z.re + z.im * z.im));
}

Complex c_sqr(Complex z1)
{
	Complex	res;

	res.re = (z1.re * z1.re) - (z1.im * z1.im);
	res.im = (2 * z1.im * z1.re);
	return (res);
}

Complex c_product(Complex z1, Complex z2)
{
	Complex res;
	res.re = (z1.re * z2.re) - (z1.im * z2.im);
	res.im = (z1.re * z2.im) + (z1.im * z2.re);
	return (res);	
}

double scaling(double nbr, double old_min, double old_max, double new_min, double new_max)
{
	return((new_max - new_min)*((nbr - old_min)/(old_max - old_min)) + new_min);
}

