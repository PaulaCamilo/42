/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:54:08 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/03/11 16:26:35 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include "../mlx/mlx.h"

# include <fcntl.h>
# include <math.h>
# include <signal.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# include <stdio.h>

# define WIDTH 1920
# define HEIGHT 1080
# define SCALE 10
# define DEFAULT_COLOR 0xFFFFFF
# define ESC_KEY 65307
# define ZOOM_IN 65451 // +
# define ZOOM_OUT 65453 // -
# define ROTATE 114 // R
# define RESET_VIEW 122 // Z
# define ARROW_UP 65362
# define ARROW_DOWN 65364
# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363
# define ISO_VIEW 49
# define TOP_VIEW 50
# define RESET_ZOOM 65288 // backspace
# define PI 3.14159265358979323846

typedef struct s_line
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;
	int	color;
}				t_line;

// struct for points
typedef struct s_point
{
	int	x;
	int	y;
	int	z; //
	int	color; //
	int	height;
	int	has_color;
}				t_point;

// struct for image data
typedef struct s_img
{
	void	*img_ptr;
	char	*address;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

typedef struct s_render
{
	t_img		img;
	void		*mlx;
	void		*win;
	t_point		**map;
	int			rows;
	int			cols;
	float		scale;
	int			has_any_color;
	int			file_has_color;
	double		rotation;
	int			offset_x;
	int			offset_y;
	int			offset_z;
	int			projection;
}				t_render;

// struct to hold Bresenham's algorithm parameters
typedef struct s_bresenham
{
	int	dx;
	int	dy;
	int	*err;
	int	sx;
	int	sy;
	int	*x1;
	int	*y1;
	int	x2;
	int	y2;
}				t_bresenham;

typedef struct s_matrix
{
	t_point	**matrix;
	int		rows;
	int		max_cols;
}				t_matrix;

// color.c
int		get_color(int z, int has_color, int color, int has_any_color);

// draw.c
void	put_pixel(t_render *render, int x, int y, int color);
void	bresenham(t_render *render, t_line *line);

// init_mlx.c
int		init_render(t_render *render, t_point **data_array, int rows,
			int max_cols);
void	initialize_render(t_render *render, t_point **data_array, int rows,
			int max_cols);
int		handle_keypress(int keycode, t_render *render);
void	handle_zoom_rotate(int keycode, t_render *render);
void	handle_move_proj(int keycode, t_render *render);
int		handle_close(t_render *render);
void	setup_and_run_mlx(t_render *render);
void	reset_image(t_render *render);
void	draw_menu(t_render *render);

// input_check.c
int		check_ac(int ac);
int		check_av(char *av);
int		check_file(char *av);
int		input_check(int ac, char **av);

// input_parsing.c
t_point	**allocate_matrix(int rows, int max_cols);
void	parse_line(char *line, t_point *matrix_row, int max_cols,
			t_render *render);
t_point	**parse_matrix(const char *filename, t_matrix *matrix_info,
			t_render *render);

// input_parsing_helpers.c
int		open_file(const char *filename);
char	*allocate_buffer(size_t size);
void	read_file(int fd, char *buffer, size_t size);

// input_parsing_helpers2.c
int		count_rows(char **lines);
int		count_columns(char *line);
int		determine_max_cols(char **lines, int rows);
void	parse_lines_matrix(char **lines, t_point **matrix,
			t_matrix *matrix_info, t_render *render);

// rendering.c
t_point	project_iso(int x, int y, int z, int scale);
void	draw_l_next_row_point(t_render *render, t_point p1, int i, int j);
t_point	get_projected_point_and_color(t_render *render, int i, int j);
void	draw_l_next_col_point(t_render *render, t_point p1, int i, int j);
void	render_map(t_render *render);

// utils.c
t_point	rotate_point(t_point point, double rotation_x);
int		ft_abs(int n);
int		rgb_to_int(char *color);
void	free_matrix(t_point **matrix, int rows);
t_point	top_projection(int x, int y, int z, int scale);

#endif
