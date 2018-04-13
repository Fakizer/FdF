/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 15:55:25 by vvlasenk          #+#    #+#             */
/*   Updated: 2016/12/21 15:55:26 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_dot	**create_dot_line(int y, char *line, t_image *im)
{
	char	**split_line;
	t_dot	**dot_l;
	int		size;
	int		x;
	int		z;

	if ((split_line = ft_strsplit(line, ' ')) == NULL)
		init_error(ERROR_SPLIT);
	size = line_len(split_line);
	im->x_len[y] = size;
	im->max_x = max_xy(im->max_x, size);
	if ((dot_l = (t_dot **)malloc(sizeof(t_dot *) * (size + 1))) == NULL)
		init_error("");
	dot_l[size] = 0;
	x = 0;
	while (split_line[x] != '\0')
	{
		z = -ft_atoi(split_line[x]);
		dot_l[x] = init_dot(z);
		im->max_z = max_xy(im->max_z, z);
		im->min_z = min_xy(im->min_z, z);
		x++;
	}
	free_split_line(split_line);
	return (dot_l);
}

void	processing_file(char *file, t_image *im)
{
	int		fd;
	size_t	n_lines;

	fd = 0;
	n_lines = 0;
	if ((n_lines = count_lines(file)) == 0)
		init_error(EMPTYFILE);
	im->max_y = n_lines;
	im->matrix = (t_dot ***)malloc(sizeof(t_dot **) * (n_lines + 1));
	if (im->matrix == NULL)
		init_error("");
	im->x_len = (int *)malloc(sizeof(int) * n_lines);
	if (im->x_len == NULL)
		init_error("");
	im->matrix[n_lines] = 0;
	if ((fd = open(file, O_RDONLY)) == ERROR)
		init_error(file);
	matrix_init(fd, im);
	if (close(fd) == ERROR)
		init_error(file);
}

size_t	count_lines(char *file)
{
	size_t	n;
	int		ret;
	char	*line;
	int		fd;

	n = 0;
	ret = ERROR;
	line = NULL;
	if ((fd = open(file, O_RDONLY)) == ERROR)
		init_error(file);
	while ((ret = get_next_line(fd, &line)) != 0)
	{
		if (ret == ERROR)
			init_error(ERROR_PROC);
		free(line);
		n++;
	}
	if (close(fd) == ERROR)
		init_error(file);
	return (n);
}

void	dot_proc(int y, int x, t_image *im)
{
	t_str	str;

	math_proc(y, x, im);
	if (x > 0)
	{
		str.p1 = im->matrix[y][x - 1];
		str.p2 = im->matrix[y][x];
		draw_pick_line(&str, set_color(&str, im), im);
	}
	if (y > 0 && im->x_len[y - 1] > x)
	{
		str.p1 = im->matrix[y - 1][x];
		str.p2 = im->matrix[y][x];
		draw_pick_line(&str, set_color(&str, im), im);
	}
}

void	pick_data_math(t_image *im)
{
	int		x;
	int		y;

	y = 0;
	while (im->matrix[y] != '\0')
	{
		x = 0;
		while (x < im->x_len[y])
		{
			dot_proc(y, x, im);
			x++;
		}
		y++;
	}
}
