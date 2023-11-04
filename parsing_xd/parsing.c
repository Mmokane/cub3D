/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 04:01:37 by mmokane           #+#    #+#             */
/*   Updated: 2023/11/04 09:04:04 by oubelhaj         ###   ########.fr       */
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

void	player_init(t_data *data, char **map, int y, int x)
{
	if (data->player->x != 0 || data->player->y != 0)
		ft_putstr_fd2("Error Multiple players\n", 2);
	data->player->x = (x * TILE_SIZE) + 16;
	data->player->y = (y * TILE_SIZE) + 16;
	if (map[y][x] == 'N')
		data->player->dir = 'N';
	else if (map[y][x] == 'S')
		data->player->dir = 'S';
	else if (map[y][x] == 'E')
		data->player->dir = 'E';
	else if (map[y][x] == 'W')
		data->player->dir = 'W';
	data->map->map[y][x] = '0';
}

void	checker(t_data *data)
{
	if (!data->map->no || !data->map->so || !data->map->we || !data->map->ea)
		ft_putstr_fd2("Missing texture\n", 2);
	else if (data->map->f == -1 || data->map->c == -1)
		ft_putstr_fd2("Missing color\n", 2);
	else if (!data->map->map[0])
		ft_putstr_fd2("Missing map\n", 2);
	else if (data->player->x == 0 || data->player->y == 0)
		ft_putstr_fd2("Missing player\n", 2);
}

char	**map_create(char **str, char *arg)
{
	int		i;
	int		args_len;
	char	**args;

	if (!str[0] || !str)
	{
		args = (char **)malloc(sizeof(char *) * 2);
		args[0] = ft_strdup(arg);
		args[1] = NULL;
		ft_free(str);
		return (args);
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
	ft_free(str);
	return (args);
}

void	parsing(t_data *data, char *str)
{
	int	fd;

	exten_check(str, ".cub");
	fd = open(str, O_RDONLY);
	if (fd < 0)
		ft_putstr_fd2("Error, cant open file\n", 2);
	init(data);
	file_reader(data, fd);
	close(fd);
	final_check(data, data->map->map);
	checker(data);
	check_sides(data->map->map);
}
