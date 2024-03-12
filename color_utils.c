/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsquarci <lsquarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:42:53 by lsquarci          #+#    #+#             */
/*   Updated: 2024/03/11 12:41:04 by lsquarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*channel color = sin(frequency * continuous_index + phase) * center + delta)*/

t_color	m_color(int i)
{
	return ((t_color){(unsigned int)(sin(0.071 * i + 1) * 127.5 + 127.5),
						(unsigned int)(sin(0.071 * i + 2) * 127.5 + 127.5),
						(unsigned int)(sin(0.071 * i + 3) * 12.5 + 127.5)});
}

t_color	j_color(int i)
{
	return ((t_color){(unsigned int)(sin(0.093 * i + 0.5) * 127.5 + 127.5),
						(unsigned int)(cos(0.033 * i + 2) * 127.5 + 127.5),
						(unsigned int)(cos(0.0623 * i + 1) * 117.5 + 127.5)});
}

t_color	s_color(int i)
{
	return ((t_color){(unsigned int)(sin(0.071 * i + 1) * 127.5 + 127.5),
						(unsigned int)(sin(0.071 * i + 2) * 127.5 + 127.5),
						(unsigned int)(sin(0.171 * i + 3) * 127.5 + 127.5)});
}

t_color	p_color(int i)
{
	return ((t_color){(unsigned int)(sin(0.095 * i + 1) * 127.5 + 127.5),
						(unsigned int)(sin(0.087 * i + 2.4) * 127.5 + 127.5),
						(unsigned int)(sin(0.178 * i + 3.6) * 127.5 + 127.5)});
}

int	color_blender(int i, t_parameters *params)
{
	t_color	color;

	if (params->type == 'm')
		color = m_color(i);
	else if (params->type == 'j')
		color = j_color(i);
	else if (params->type == 's')
		color = s_color(i);
	else if (params->type == 'p')
		color = p_color(i);
	return (get_hexcolor(color.r, color.g, color.b));
}
