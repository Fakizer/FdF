/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 15:48:00 by vvlasenk          #+#    #+#             */
/*   Updated: 2016/12/21 15:48:01 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		set_color(t_str *str, t_image *im)
{
	int		h;
	int		color;
	int		step;

	h = max_xy(-str->p1->z, -str->p2->z);
	step = (im->max_z - im->min_z) / COLORS_NUMBER;
	if (h < step * 0)
		color = BLUE;
	else if (h < step * 1)
		color = GREEN;
	else if (h < step * 2)
		color = BROWN;
	else
		color = WHITE;
	return (color);
}
