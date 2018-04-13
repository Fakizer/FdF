/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 13:27:26 by vvlasenk          #+#    #+#             */
/*   Updated: 2016/12/10 13:27:27 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "get_next_line.h"
# include "libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <math.h>
# include <string.h>
# include <errno.h>

# include <stdio.h>

# define PROG_NAME			"fdf"
# define USAGE				"usage: ./fdf [file]"
# define SHOW_HELP			"Press 'F1' to show/hide help"
# define ERROR_MLX			"minilibx error occured"
# define ERROR_PROC			"error while reading file"
# define EMPTYFILE			"error: the file is empty"
# define ERROR_SPLIT		"error while splitting line"
# define ERROR_END			"error: unknown endian"
# define EXIT_OK			0
# define EXIT_ERROR			1
# define MY_LITTLE_END		0
# define MY_BIG_END			1
# define ERROR				-1
# define SUCCESS			1
# define WIDTH				1390
# define HEIGTH				1390
# define COLORS_NUMBER		3
# define ERROR_EXIT			1
# define ERROR_READ			-1
# define DEFAULT_ELEVATION	1
# define DEFAULT_SCALE_STEP	1
# define DEFAULT_SHIFT_STEP	5
# define DEFAULT_ANGLE_STEP	96
# define DEFAULT_ELEV_STEP	1
# define COEF_FAST_SCALE	9
# define COEF_FAST_SHIFT	45
# define COEF_FAST_ANGLE	8
# define COEF_FAST_ELEV		4

typedef unsigned char		t_tsvet;

typedef enum				e_bool
{
	FT_FALSE,
	FT_TRUE
}							t_bool;

typedef enum				e_key
{
	ESC = 53,
	F1 = 122,
	LEFT_ARROW = 123,
	RIGHT_ARROW = 124,
	UP_ARROW = 126,
	DOWN_ARROW = 125,
	NUM_PLUS = 69,
	NUM_MINUS = 78,
	NUM_STAR = 67,
	NUM_4 = 86,
	NUM_6 = 88,
	NUM_8 = 91,
	NUM_2 = 84,
	LEFT_KEY = 43,
	RIGHT_KEY = 47,
	HOME = 115,
	PG_UP = 116,
	PG_DOWN = 121
}							t_key;

typedef enum				e_color
{
	RED = 0xA00000,
	WHITE = 0xFFFFFF,
	BROWN = 0x663300,
	GREEN = 0x007000,
	BLUE = 0x0033CC
}							t_color;

typedef struct				s_dot
{
	int						z;
	int						sx;
	int						sy;
	int						sz;
	int						px;
	int						py;
}							t_dot;

typedef struct				s_str
{
	t_dot					*p1;
	t_dot					*p2;
}							t_str;

typedef struct				s_image
{
	void					*mlx;
	void					*win;
	t_dot					***matrix;
	int						*x_len;
	void					*pick;
	char					*pick_data;
	int						bpp;
	int						size_line;
	int						end;
	int						max_x;
	int						max_y;
	int						max_z;
	int						min_z;
	t_bool					show_help;
	t_bool					fast_trans;
	int						scale_step;
	int						shift_step;
	int						angle_step;
	int						elev_step;
	int						scale;
	double					elev;
	int						x_shift;
	int						y_shift;
	double					x_angle;
	double					y_angle;
	double					z_angle;
}							t_image;

typedef struct				s_bresen
{
	int						x0;
	int						y0;
	int						x1;
	int						y1;
	int						dx;
	int						dy;
	int						sx;
	int						sy;
	int						err;
	int						e2;
}							t_bresen;

void						check_error(int ac);
t_image						*init_im(void);
void						init_def_coef(t_image *im);
void						init_error(char *pref);
void						processing_file(char *file, t_image *im);
size_t						count_lines(char *file);
void						matrix_init(int fd, t_image *im);
t_dot						**create_dot_line(int y, char *line, t_image *im);
size_t						line_len(char **split_line);
int							max_xy(int x, int y);
int							min_xy(int x, int y);
t_dot						*init_dot(int z);
void						free_split_line(char **split_line);
void						scale_win(t_image *im);
int							key_hook(int keycode, t_image *im);
int							expose_hook(t_image *im);
void						pick_create(t_image *im);
t_bool						push_keys(int keycode, t_image *im);
t_bool						push_zoom(int k, t_image *im);
t_bool						push_rotation(int k, t_image *im);
t_bool						push_movement(int k, t_image *im);
t_bool						push_special(int k, t_image *im);
void						switch_push(t_image *im);
void						pick_data_math(t_image *im);
void						dot_proc(int y, int x, t_image *im);
void						math_proc(int y, int x, t_image *im);
void						scale_proc(int y, int x, t_image *im);
void						rot_proc(t_dot *dot, t_image *im);
void						rotate_z(t_dot *dot, t_image *im);
void						rotate_y(t_dot *dot, t_image *im);
void						rotate_x(t_dot *dot, t_image *im);
void						iso_proc(t_dot *dot);
void						shift_proc(t_dot *dot, t_image *im);
void						push_help(t_image *im);
void						draw_pick_line(t_str *str, int color, t_image *im);
int							set_color(t_str *str, t_image *im);

#endif
