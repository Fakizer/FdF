/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_proc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 15:48:57 by vvlasenk          #+#    #+#             */
/*   Updated: 2016/12/21 15:48:58 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(t_dot *dot, t_image *im)
{
	int				tx;
	int				ty;
	int				tz;
	double			gamma;

	tx = dot->sx;
	ty = dot->sy;
	tz = dot->sz;
	gamma = im->x_angle;
	dot->sx = tx;
	dot->sy = ty * cos(gamma) - tz * sin(gamma);
	dot->sz = ty * sin(gamma) + tz * cos(gamma);
}

void	rotate_y(t_dot *dot, t_image *im)
{
	int				tx;
	int				ty;
	int				tz;
	double			gamma;

	tx = dot->sx;
	ty = dot->sy;
	tz = dot->sz;
	gamma = im->y_angle;
	dot->sx = tx * cos(gamma) + tz * sin(gamma);
	dot->sy = ty;
	dot->sz = -tx * sin(gamma) + tz * cos(gamma);
}

void	rotate_z(t_dot *dot, t_image *im)
{
	int				tx;
	int				ty;
	int				tz;
	double			gamma;

	tx = dot->sx;
	ty = dot->sy;
	tz = dot->sz;
	gamma = im->z_angle;
	dot->sx = tx * cos(gamma) - ty * sin(gamma);
	dot->sy = tx * sin(gamma) + ty * cos(gamma);
	dot->sz = tz;
}

void	rot_proc(t_dot *dot, t_image *im)
{
	rotate_x(dot, im);
	rotate_y(dot, im);
	rotate_z(dot, im);
}
