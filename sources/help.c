/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 15:44:30 by vvlasenk          #+#    #+#             */
/*   Updated: 2016/12/21 15:44:31 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	show_help(t_image *im)
{
	mlx_string_put(im->mlx, im->win, 20, 60, WHITE, "Controls:");
	mlx_string_put(im->mlx, im->win, 20, 80, WHITE, "ESC       : quit");
	mlx_string_put(im->mlx, im->win, 20, 100, WHITE, "Arrows    : move");
	mlx_string_put(im->mlx, im->win, 20, 120, WHITE, "Num +/-   : zoom");
	mlx_string_put(im->mlx, im->win, 20, 140, WHITE,
		"Num 8/2   : rotate around X-axis");
	mlx_string_put(im->mlx, im->win, 20, 160, WHITE,
		"Num 4/6   : rotate around Y-axis");
	mlx_string_put(im->mlx, im->win, 20, 180, WHITE,
		"< / >     : rotate around Z-axis");
	mlx_string_put(im->mlx, im->win, 20, 200,
		WHITE, "PgUp/PgDn : adjust height");
	mlx_string_put(im->mlx, im->win, 20, 220, WHITE, "Home      : reset");
	mlx_string_put(im->mlx, im->win, 20, 240, WHITE,
		"Num *     : fast transformation");
}

void	push_help(t_image *im)
{
	mlx_string_put(im->mlx, im->win, 20, 40, WHITE, SHOW_HELP);
	mlx_string_put(im->mlx, im->win, 340, 40, WHITE, "Fast transformation: ");
	if (im->fast_trans == FT_TRUE)
		mlx_string_put(im->mlx, im->win, 550, 40, GREEN, "ON");
	else
		mlx_string_put(im->mlx, im->win, 550, 40, RED, "OFF");
	if (im->show_help == FT_TRUE)
		show_help(im);
}
