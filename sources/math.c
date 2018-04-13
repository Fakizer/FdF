/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 15:49:59 by vvlasenk          #+#    #+#             */
/*   Updated: 2016/12/21 15:50:00 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	shift_proc(t_dot *dot, t_image *im)
{
	dot->px = dot->px + im->x_shift;
	dot->py = dot->py + im->y_shift;
}

void	iso_proc(t_dot *dot)
{
	double	iso1;
	double	iso2;

	iso1 = 0.5;
	iso2 = 0.5;
	dot->px = (iso1 * dot->sx) - (iso2 * dot->sy);
	dot->py = dot->sz + ((iso1 / 2) * dot->sx) + ((iso2 / 2) * dot->sy);
}

void	scale_proc(int y, int x, t_image *im)
{
	t_dot	*dot;

	dot = im->matrix[y][x];
	dot->sx = (x - (im->max_x / 2)) * im->scale;
	dot->sy = (y - (im->max_y / 2)) * im->scale;
	dot->sz = dot->z * (im->scale / 30.0) * im->elev;
}

void	math_proc(int y, int x, t_image *im)
{
	scale_proc(y, x, im);
	rot_proc(im->matrix[y][x], im);
	iso_proc(im->matrix[y][x]);
	shift_proc(im->matrix[y][x], im);
}

void	scale_win(t_image *im)
{
	int		diag;
	int		scale;

	diag = sqrt(pow(im->max_x, 2) + pow(im->max_y, 2));
	scale = WIDTH / diag;
	if (scale < 1)
		im->scale = 1;
	else
		im->scale = scale;
}
