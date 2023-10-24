/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moskir <moskir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 02:34:54 by mmokane           #+#    #+#             */
/*   Updated: 2023/10/24 02:26:17 by moskir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <errno.h>
# include "../libft/libft.h"
# include "get_next_line.h"

# define TILE_SIZE 32

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
	char	*dr;
	char	**map;
	int		f;
	int		c;
	int		h;
	int		w;
}	t_map;

typedef struct s_player
{
	int		x;
	int		y;
	char	dir;
}	t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		*map;
	t_player	*player;
}	t_game;

//////////////////////checks.c//////////////////////
int		map_check(char *line);
void	final_check(t_game *game, char **map);
void	exten_check(char *str, char *extension);
void	map_pars(t_game *game, char *line, int fd);
void	file_reader(t_game *game, int fd);
void	player_init(t_game *game, char **map, int y, int x);

//////////////////////map_parsing.c//////////////////////
int		map_tokens(char *arg);
int		lines_pars(t_game *game, char *line);
void	check_sides(char **map);
void	texture_pars(t_game *game, char *line, int token, int i);
void	ft_putstr_fd2(char *s, int fd);

//////////////////////map_parsing2.c//////////////////////
int		player_exist(char c);
int		lines_value(t_game *game);
int		color_value(char *line, int *i);
void	color_pars(t_game *game, char *line, int token, int i);

//////////////////////parsing_utils.c//////////////////////
void	space_skipper(char *s, int *i);
void	check_nums(char *line);
void	data_init(t_game *game);
void	init(t_game *game);

//////////////////////parsing.c//////////////////////
char	**map_create(char **str, char *arg);
void	parsing(t_game *game, char *str);

//////////////////////utils.c////////////////////////
void	ft_free(char **args);

#endif