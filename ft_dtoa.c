/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsquarci <lsquarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:09:21 by lsquarci          #+#    #+#             */
/*   Updated: 2024/03/11 12:43:24 by lsquarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int n_tu(int n1, int count)
{
	int result;
	result = 1;
	while(count-- > 0)
		result *= n1;

	return result;
}

static void calculate_length(float f, t_dtoa *c) {
	if (f > 1) 
		c->length = 0;     
	else 
		c->length = 1;    
	while (f > 1) 
	{
		c->length++;
		f /= 10;
	}
}

static void append_digits_to_string(char r[], t_dtoa *c) {
	while (c->i >= 0) 
	{
		if (c->i == (c->length)) 
			r[c->i] = '\0';         
		else if (c->i == (c->position)) 
			r[c->i] = '.';         
		else if (c->sign == '-' && c->i == 0) 
			r[c->i] = '-';         
		else 
		{
			r[c->i] = (c->n1 % 10) + '0';
			c->n1 /= 10;
		}
		c->i--;
	}
}

void ft_dtoa(float f, char r[], t_dtoa *c)
{
	c->sign = -1;  

	if (f < 0) 
	{
		c->sign = '-';
		f *= -1;
		c->length++;
		c->position++;
	}
	c->n2 = f;
	c->n1 = f;
	c->length = 0;  
	c->length2 = 0; 
	while ((c->n2 - (float)c->n1) != 0.0 && !((c->n2 - (float)c->n1) < 0.0)) 
	{
		c->n2 = f * (n_tu(10.0, c->length2 + 1));
		c->n1 = c->n2;
		c->length2++;
	}
	calculate_length(f, c);
	c->position = c->length;
	c->length = c->length + 1 + c->length2;
	c->n1 = c->n2;
	c->i = c->length;
	append_digits_to_string(r, c);
}




