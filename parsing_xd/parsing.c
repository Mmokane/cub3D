/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 04:01:37 by mmokane           #+#    #+#             */
/*   Updated: 2023/10/07 09:46:05 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	argslen(char **args)
{
	int	i;

	if (!args)
		return (0);
	i = 0;
	while (args[i])
		i++;
	return (i + 1);
}
void	player_init(t_game *game, char **map, int y, int x)
{
	if (game->player->x != 0 || game->player->y != 0)
		ft_putstr_fd("Error Multiple players\n", 2);
	game->player->x = (x * TILE_SIZE) + 16;
	game->player->y = (y * TILE_SIZE) + 16;
	if (map[y][x] == 'N')
		game->player->dir = 'N';
	else if (map[y][x] == 'S')
		game->player->dir = 'S';
	else if (map[y][x] == 'E')
		game->player->dir = 'E';
	else if (map[y][x] == 'W')
		game->player->dir = 'W';
	game->map->map[y][x] = '0';
}
char	**map_create(char **str, char *arg)
{
	int i;
	int args_len;
	char **args;
	
	if (!str[0] || !str)
	{
		args = (char **)malloc(sizeof(char *) * 2);
		args[0] = ft_strdup(arg);
		args[1] = NULL;
		return(args);
	}
	args_len = argslen(str);
	args = (char **)malloc(sizeof(char *) * (args_len + 1));
	i = 0;
	while (str[i])
	{
		args[i] = ft_strdup(str[i]);
		i++;
	}
	args[i] = ft_strdup(arg);
	args[i + 1] = NULL;
	return (args);
}


void	parsing(t_game *game, char *str)
{
	int fd;

	exten_check(str, ".cub");
	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nCan't open file\n", 2);
		exit(1);
	}
	init(game);//need to init data here :3 dont forget
	file_reader(game, fd);
	close(fd);
	final_check(game, game->map->map);
	check_sides(game->map->map);
}

