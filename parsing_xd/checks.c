/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 02:36:24 by mmokane           #+#    #+#             */
/*   Updated: 2023/10/06 05:28:06 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	map_check(char *line)//is map//done
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != 'S' && line[i] != 'N'
			&& line[i] != '0' && line[i] != 'E'
			&& line[i] != '\n' && line[i] != '1'
			&& line[i] != 'W')
			return (0);
		i++;
	}
	return (1);
}

void	final_check(t_game *game, char **map)
{
	int i;
	int j;

	i = 0;
	printf("map*-**-\n");
	printf("%s\n", map[0]);
	while(map[++i] && lines_value(game) == 0)
	{
		j = -1;
		while(map[i][++j])
		{
			if(map[i][j] == '0' || player_exist(map[i][j]))
			{
				if (j > (int)ft_strlen(map[i + 1]) 
					|| j > (int)ft_strlen(map[i - 1]))
					{
						write(2, "Error Invalid map\n", 18);
						exit(1);
					}
				if (map[i][j - 1] == ' ' || map[i][j - 1] == '\0'
					|| map[i][j + 1] == ' ' || map[i][j + 1] == '\0'
					|| map[i - 1][j] == ' ' || map[i - 1][j] == '\0'
					|| map[i + 1][j] == ' ' || map[i + 1][j] == '\0')
					{
						write(2, "Error Invalid map\n", 18);
						exit(1);
					}
			}
			if (map[i][j] == 'S' || map[i][j] == 'N'
				|| map[i][j] == 'E' || map[i][j] == 'W')
				player_init(game, map, i, j);
		}
	}
}

void	exten_check(char *str, char *extension)//done
{
	char *ext;

	ext = ft_strrchr(str, '.');
	if (!ext)
	{
		ft_putstr_fd("Error No extension\n", 2);
		exit(1);
	}
	else if (ft_strncmp(ext, extension, 5))
	{
		ft_putstr_fd("Error Wrong extension\n", 2);
		exit(1);
	}
}

void	map_pars(t_game *game, char *line, int fd)
{
	char *tmp;

	while (line)
	{
		if (!map_check(line))
		{
			write(2, "ErrorInvalid map\n", 18);
			exit(1);
		}
		game->map->H++;
		tmp = ft_strtrim(line, "\n");
		if (game->map->W < ((int)ft_strlen(tmp)))
			game->map->W = ((int)ft_strlen(tmp));
		game->map->map = map_create(game->map->map, tmp);//adv
		line = get_next_line(fd);
	}
}

void	file_reader(t_game *game, int fd)//not done
{
	char	*line;

	line = get_next_line(fd);
	printf("line: %s\n", line);
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
	printf("%s\n hhhhhhh", line);
}