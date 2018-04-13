/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 13:27:43 by vvlasenk          #+#    #+#             */
/*   Updated: 2016/12/10 13:27:45 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_bool	push_keys(int keycode, t_image *im)
{
	if (push_special(keycode, im) == FT_TRUE)
		return (FT_TRUE);
	else if (push_movement(keycode, im) == FT_TRUE)
		return (FT_TRUE);
	else if (push_rotation(keycode, im) == FT_TRUE)
		return (FT_TRUE);
	else if (push_zoom(keycode, im) == FT_TRUE)
		return (FT_TRUE);
	return (FT_FALSE);
}

void	pick_create(t_image *im)
{
	if ((im->pick = mlx_new_image(im->mlx, WIDTH, HEIGTH)) == NULL)
		init_error(ERROR_MLX);
	im->pick_data = mlx_get_data_addr(im->pick, &im->bpp,
		&im->size_line, &im->end);
	pick_data_math(im);
	mlx_put_image_to_window(im->mlx, im->win, im->pick, 0, 0);
	mlx_destroy_image(im->mlx, im->pick);
}

int		expose_hook(t_image *im)
{
	pick_create(im);
	push_help(im);
	return (0);
}

int		key_hook(int keycode, t_image *im)
{
	if (keycode == ESC)
		exit(EXIT_OK);
	if (push_keys(keycode, im) == FT_TRUE)
		expose_hook(im);
	return (0);
}

int		main(int ac, char **av)
{
	t_image		*im;

	check_error(ac);
	if ((im = init_im()) == NULL)
		init_error("");
	if ((im->mlx = mlx_init()) == NULL)
		init_error(ERROR_MLX);
	if ((im->win = mlx_new_window(im->mlx, WIDTH, HEIGTH, PROG_NAME)) == NULL)
		init_error(ERROR_MLX);
	processing_file(av[1], im);
	scale_win(im);
	mlx_key_hook(im->win, key_hook, im);
	mlx_expose_hook(im->win, expose_hook, im);
	mlx_loop(im->mlx);
	return (0);
}
