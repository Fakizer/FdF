/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 15:51:01 by vvlasenk          #+#    #+#             */
/*   Updated: 2016/12/21 15:51:02 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	switch_push(t_image *im)
{
	im->fast_trans = (im->fast_trans == FT_FALSE) ? FT_TRUE : FT_FALSE;
	if (im->fast_trans == FT_TRUE)
	{
		im->scale_step += COEF_FAST_SCALE;
		im->shift_step += COEF_FAST_SHIFT;
		im->angle_step /= COEF_FAST_ANGLE;
		im->elev_step += COEF_FAST_ELEV;
	}
	else
	{
		im->scale_step -= COEF_FAST_SCALE;
		im->shift_step -= COEF_FAST_SHIFT;
		im->angle_step *= COEF_FAST_ANGLE;
		im->elev_step -= COEF_FAST_ELEV;
	}
}

t_bool	push_special(int k, t_image *im)
{
	if (k == F1)
		im->show_help = (im->show_help == FT_FALSE) ? FT_TRUE : FT_FALSE;
	else if (k == NUM_STAR)
		switch_push(im);
	else if (k == HOME)
	{
		init_def_coef(im);
		scale_win(im);
	}
	if (k == F1 || k == NUM_STAR || k == HOME)
		return (FT_TRUE);
	else
		return (FT_FALSE);
}

t_bool	push_movement(int k, t_image *im)
{
	if (k == LEFT_ARROW)
		im->x_shift -= im->shift_step;
	else if (k == RIGHT_ARROW)
		im->x_shift += im->shift_step;
	else if (k == UP_ARROW)
		im->y_shift -= im->shift_step;
	else if (k == DOWN_ARROW)
		im->y_shift += im->shift_step;
	else if (k == PG_UP)
		im->elev += im->elev_step;
	else if (k == PG_DOWN)
		im->elev -= im->elev_step;
	if (k == LEFT_ARROW || k == RIGHT_ARROW || k == UP_ARROW || k == DOWN_ARROW
		|| k == PG_UP || k == PG_DOWN)
		return (FT_TRUE);
	else
		return (FT_FALSE);
}

t_bool	push_rotation(int k, t_image *im)
{
	if (k == NUM_8)
		im->x_angle -= M_PI / im->angle_step;
	else if (k == NUM_2)
		im->x_angle += M_PI / im->angle_step;
	else if (k == NUM_4)
		im->y_angle += M_PI / im->angle_step;
	else if (k == NUM_6)
		im->y_angle -= M_PI / im->angle_step;
	else if (k == LEFT_KEY)
		im->z_angle -= M_PI / im->angle_step;
	else if (k == RIGHT_KEY)
		im->z_angle += M_PI / im->angle_step;
	if (k == NUM_8 || k == NUM_2 || k == NUM_4 || k == NUM_6
		|| k == LEFT_KEY || k == RIGHT_KEY)
		return (FT_TRUE);
	else
		return (FT_FALSE);
}

t_bool	push_zoom(int k, t_image *im)
{
	if (k == NUM_PLUS)
		im->scale += im->scale_step;
	else if (k == NUM_MINUS)
		im->scale -= im->scale_step;
	if (k == NUM_PLUS || k == NUM_MINUS)
		return (FT_TRUE);
	else
		return (FT_FALSE);
}
