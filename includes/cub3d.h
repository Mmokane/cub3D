/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 02:34:54 by mmokane           #+#    #+#             */
/*   Updated: 2023/10/07 09:34:33 by mmokane          ###   ########.fr       */
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
	int		F;
	int		C;
	int		H;
	int		W;
}	t_map;

typedef struct s_player
{
	int		x;
	int		y;
	char	dir;
}	t_player;
typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	*map;
	t_player *player;
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

//////////////////////map_parsing2.c//////////////////////
int 	player_exist(char c);
int 	lines_value(t_game *game);
int 	color_value(char *line, int *i);
void	color_pars(t_game *game, char *line, int token, int i);

//////////////////////parsing_utils.c//////////////////////
void	space_skipper(char *s, int *i);
void	check_nums(char *line);
void	data_init(t_game *game);
void	init(t_game *game);

//////////////////////parsing.c//////////////////////
char	**map_create(char **str, char *arg);
void	parsing(t_game *game, char *str);


#endif



// void	checker(t_cub *cub, char **map)
// {
// 	int		i;
// 	int		j;

// 	i = 0;
// 	while (map[++i] && set_lines(cub) == 0)
// 	{
// 		j = -1;
// 		while (map[i][++j])
// 		{
// 			if (map[i][j] == '0' || is_player(map[i][j]))
// 			{
// 				if (j > (int)ft_strlen(map[i + 1])
// 					|| j > (int)ft_strlen(map[i - 1]) || j == 0)
// 					exit_str("Error: Invalid map");
// 				if (map[i][j - 1] == ' ' || map[i][j - 1] == '\0'
// 					|| map[i][j + 1] == ' ' || map[i][j + 1] == '\0'
// 					|| map[i - 1][j] == ' ' || map[i - 1][j] == '\0'
// 					|| map[i + 1][j] == ' ' || map[i + 1][j] == '\0')
// 					exit_error("Invalid map", map[i]);
// 			}
// 			if (map[i][j] == 'N' || map[i][j] == 'S'
// 				|| map[i][j] == 'W' || map[i][j] == 'E')
// 				add_player(cub, map, i, j);
// 		}
// 	}
// }

// char	**advanced_add(char **strs, char *arg)
// {
// 	char	**args;
// 	int		wlen;
// 	int		i;

// 	if (!strs[0] || !strs)
// 	{
// 		args = (char **)malloc(sizeof(char *) * 2);
// 		args[0] = ft_strdup(arg);
// 		args[1] = NULL;
// 		free_loop(strs);
// 		return (args);
// 	}
// 	wlen = argslen(strs);
// 	args = (char **)malloc(sizeof(char *) * (wlen + 1));
// 	i = -1;
// 	while (strs[++i])
// 		args[i] = ft_strdup(strs[i]);
// 	args[i] = ft_strdup(arg);
// 	args[i + 1] = NULL;
// 	free_loop(strs);
// 	return (args);
// }