/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 02:36:24 by mmokane           #+#    #+#             */
/*   Updated: 2023/10/11 16:22:19 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	map_check(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != 'S' && line[i] != 'N'
			&& line[i] != '0' && line[i] != 'E'
			&& line[i] != '\n' && line[i] != '1'
			&& line[i] != 'W' && line[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

void	final_check(t_game *game, char **map)
{
	int		i;
	int		j;

	i = -1;
	while (map[++i] && lines_value(game) == 0)
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '0' || player_exist(map[i][j]))
			{
				if (j > (int)ft_strlen(map[i + 1])
					|| j > (int)ft_strlen(map[i - 1]) || j == 0)
					ft_putstr_fd2("Error: Invalid map\n", 2);
				if (map[i][j - 1] == ' ' || map[i][j - 1] == '\0'
					|| map[i][j + 1] == ' ' || map[i][j + 1] == '\0'
					|| map[i - 1][j] == ' ' || map[i - 1][j] == '\0'
					|| map[i + 1][j] == ' ' || map[i + 1][j] == '\0')
					ft_putstr_fd2("Error: Invalid map\n", 2);
			}
			if (map[i][j] == 'S' || map[i][j] == 'N'
				|| map[i][j] == 'E' || map[i][j] == 'W')
				player_init(game, map, i, j);
		}
	}
}

void	exten_check(char *str, char *extension)
{
	char	*ext;

	ext = ft_strrchr(str, '.');
	if (!ext)
		ft_putstr_fd2("Error Wrong extension\n", 2);
	else if (ft_strncmp(ext, extension, 5))
		ft_putstr_fd2("Error Wrong extension\n", 2);
}

void	map_pars(t_game *game, char *line, int fd)
{
	char	*tmp;

	while (line)
	{
		if (!map_check(line))
			ft_putstr_fd2("Error Invalid map\n", 2);
		game->map->h++;
		tmp = ft_strtrim(line, "\n");
		if (game->map->w < ((int)ft_strlen(tmp)))
			game->map->w = ((int)ft_strlen(tmp));
		game->map->map = map_create(game->map->map, tmp);
		line = get_next_line(fd);
	}
}

void	file_reader(t_game *game, int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (line[0] != '\n')
		{
			if (lines_pars(game, line))
			{
				map_pars(game, line, fd);
				return ;
			}
		}
		free(line);
		line = get_next_line(fd);
	}
}
