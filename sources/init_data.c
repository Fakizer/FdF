/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 15:53:15 by vvlasenk          #+#    #+#             */
/*   Updated: 2016/12/21 15:53:16 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_def_coef(t_image *im)
{
	im->scale = 0;
	im->elev = DEFAULT_ELEVATION;
	im->x_shift = WIDTH / 2;
	im->y_shift = HEIGTH / 2;
	im->x_angle = 0;
	im->y_angle = 0;
	im->z_angle = 0;
}

t_image	*init_im(void)
{
	t_image		*im;

	if ((im = (t_image*)malloc(sizeof(t_image))) == NULL)
		return (NULL);
	im->mlx = NULL;
	im->win = NULL;
	im->matrix = NULL;
	im->x_len = NULL;
	im->pick = NULL;
	im->pick_data = NULL;
	im->bpp = 0;
	im->size_line = 0;
	im->end = ERROR;
	im->max_x = 0;
	im->max_y = 0;
	im->max_z = 0;
	im->min_z = 0;
	im->show_help = FT_FALSE;
	im->fast_trans = FT_FALSE;
	im->scale_step = DEFAULT_SCALE_STEP;
	im->shift_step = DEFAULT_SHIFT_STEP;
	im->angle_step = DEFAULT_ANGLE_STEP;
	im->elev_step = DEFAULT_ELEV_STEP;
	init_def_coef(im);
	return (im);
}

t_dot	*init_dot(int z)
{
	t_dot	*dot;

	dot = (t_dot *)malloc(sizeof(t_dot));
	if (dot == NULL)
		return (NULL);
	dot->z = z;
	dot->sx = 0;
	dot->sy = 0;
	dot->sz = 0;
	dot->px = 0;
	dot->py = 0;
	return (dot);
}

void	matrix_init(int fd, t_image *im)
{
	char	*line;
	int		ret;
	int		y;

	line = NULL;
	ret = ERROR;
	y = 0;
	while ((ret = get_next_line(fd, &line)) != 0)
	{
		if (ret == ERROR)
			init_error(ERROR_PROC);
		im->matrix[y] = create_dot_line(y, line, im);
		free(line);
		y++;
	}
}
