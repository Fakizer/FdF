/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 15:45:51 by vvlasenk          #+#    #+#             */
/*   Updated: 2016/12/21 15:45:52 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	img_pixel_put(int x, int y, int color, t_image *im)
{
	t_tsvet			r;
	t_tsvet			g;
	t_tsvet			b;

	r = (color & 0xFF0000) >> 16;
	g = (color & 0x00FF00) >> 8;
	b = (color & 0x0000FF);
	if (x >= 0 && y >= 0 && x < WIDTH && y < HEIGTH)
	{
		if (im->end == MY_LITTLE_END)
		{
			im->pick_data[(y * im->size_line) + ((im->bpp / 8) * x)] = b;
			im->pick_data[(y * im->size_line) + ((im->bpp / 8) * x) + 1] = g;
			im->pick_data[(y * im->size_line) + ((im->bpp / 8) * x) + 2] = r;
		}
		else if (im->end == MY_BIG_END)
		{
			im->pick_data[(y * im->size_line) + ((im->bpp / 8) * x) + 1] = r;
			im->pick_data[(y * im->size_line) + ((im->bpp / 8) * x) + 2] = g;
			im->pick_data[(y * im->size_line) + ((im->bpp / 8) * x) + 3] = b;
		}
		else
			init_error(ERROR_END);
	}
}

void	init_bresen(t_bresen *b, t_str *str)
{
	b->x0 = str->p1->px;
	b->y0 = str->p1->py;
	b->x1 = str->p2->px;
	b->y1 = str->p2->py;
	b->dx = abs(b->x1 - b->x0);
	b->dy = abs(b->y1 - b->y0);
	b->sx = (b->x0 < b->x1) ? 1 : -1;
	b->sy = (b->y0 < b->y1) ? 1 : -1;
	b->err = ((b->dx > b->dy) ? b->dx : -(b->dy)) / 2;
}

void	draw_pick_line(t_str *str, int color, t_image *im)
{
	t_bresen		b;

	init_bresen(&b, str);
	while (1)
	{
		img_pixel_put(b.x0, b.y0, color, im);
		if (b.x0 == b.x1 && b.y0 == b.y1)
			break ;
		b.e2 = b.err;
		if (b.e2 > -(b.dx))
		{
			b.err -= b.dy;
			b.x0 += b.sx;
		}
		if (b.e2 < b.dy)
		{
			b.err += b.dx;
			b.y0 += b.sy;
		}
	}
}
