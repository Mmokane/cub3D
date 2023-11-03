/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 02:34:54 by mmokane           #+#    #+#             */
/*   Updated: 2023/11/03 17:06:44 by oubelhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# define TILE_SIZE 64
# define W_KEY 13
# define S_KEY 1
# define A_KEY 0
# define D_KEY 2
# define LEFT 123
# define RIGHT 124
# define ESC_KEY 53
# define RADIUS 2.0
# define TEXTURE_HEIGHT 64
# define TEXTURE_WIDTH 64
# define EA 0
# define NO 1
# define SO 2
# define WE 3

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <errno.h>
# include <math.h>
# include <mlx.h>
# include "../libft/libft.h"
# include "get_next_line.h"

enum e_content
{
	T_WE,
	T_SO,
	T_EA,
	T_NO,
	T_Error,
	T_F,
	T_C,
};

typedef struct s_map
{
	char	*we;
	char	*no;
	char	*ea;
	char	*so;
	char	**map;
	int		f;
	int		c;
	int		h;
	int		w;
}	t_map;

typedef struct	s_cords
{
	double	x_intercept;
	double	y_intercept;
	double	x_step;
	double	y_step;
	double	hit;
}	t_cords;

typedef struct	s_point
{
	int				x;
	int				y;
	int				color;
}					t_point;

typedef struct s_wall
{
	float	top_pix;
	float	bot_pix;
}		t_wall;

typedef struct	s_textures
{
	void	*img;
	void	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_textures;

typedef struct	s_ray
{
	double	angle;
	double	wall_hit_x;
	double	wall_hit_y;
	double	distance;
	int		is_down;
	int		is_up;
	int		is_right;
	int		is_left;
	double	x_intercept_h;
	double	x_intercept_v;
	double	y_intercept_h;
	double	y_intercept_v;
	double	x_step_h;
	double	x_step_v;
	double	y_step_h;
	double	y_step_v;
	float	dist_projection_plane;
	float	wall_strip_h;
	int		hit_vert;
	t_wall	*wall_cords;
}		t_ray;

typedef struct s_player
{
	double	x;
	double	y;
	char	dir;
	double	fov;
	double	walk_direction;
	double	turn_direction;
	double	move_speed;
	double	rotation_speed;
	double	rot_angle;
}	t_player;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			win_width;
	int			win_height;
	int			num_of_rays;
	t_ray		*rays;
	t_player	*player;
	t_textures	*textures;
	t_map		*map;
}	t_data;

//////////////////////checks.c//////////////////////
int		map_check(char *line);
void	final_check(t_data *data, char **map);
void	exten_check(char *str, char *extension);
void	map_pars(t_data *data, char *line, int fd);
void	file_reader(t_data *data, int fd);
void	player_init(t_data *data, char **map, int y, int x);

//////////////////////map_parsing.c//////////////////////
int		map_tokens(char *arg);
int		lines_pars(t_data *data, char *line);
void	check_sides(char **map);
void	texture_pars(t_data *data, char *line, int token, int i);
void	ft_putstr_fd2(char *s, int fd);

//////////////////////map_parsing2.c//////////////////////
int		player_exist(char c);
int		lines_value(t_data *data);
int		color_value(char *line, int *i);
void	color_pars(t_data *data, char *line, int token, int i);

//////////////////////parsing_utils.c//////////////////////
void	space_skipper(char *s, int *i);
void	check_nums(char *line);
void	data_init(t_data *data);
void	init(t_data *data);

//////////////////////parsing.c//////////////////////
char	**map_create(char **str, char *arg);
void	parsing(t_data *data, char *str);

//////////////////////utils.c////////////////////////
void	ft_free(char **args);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);

int		key_press(int keycode, t_data *data);
int		key_release(int keycode, t_data *data);
int		close_game(t_data *data);

void	init_ray(t_ray *ray, double ray_angle);
void	init_player_data(t_data *data);
void	init_mlx_data(t_data *data);

double	get_distance(int px, int py, int hx, int hy);

void	draw_2d_map(t_data *data);
void	render_player(t_data *data);
void	horizontal_intersections(t_ray *ray, t_data *data, t_cords *horz);
void	vertical_intersections(t_ray *ray, t_data *data, t_cords *vert);
int		is_wall(double x, double y, t_data *data);
void    distance_to_wall(t_ray *ray, t_data *data, t_cords horz, t_cords vert);
void    get_ray_data(t_data *data, t_ray *ray);
int		get_texture_pixel_color(int x, int y, t_data *data);
int		get_textures(t_ray *ray);
void	load_textures(t_data *data);
void	cast_rays(t_data *data);
double	norm_angle(double angle);
void	my_mlx_clear_image(t_data *data);

#endif