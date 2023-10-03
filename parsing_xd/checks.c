/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 02:36:24 by mmokane           #+#    #+#             */
/*   Updated: 2023/10/03 03:09:02 by mmokane          ###   ########.fr       */
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


void	exten_check(char *str, char *extension)//done
{
	char *ext;

	ext = ft_strrchr(str, '.');
	if (!ext)
	{
		ft_putstr_fd("Error\nNo extension\n", 2);
		exit(1);
	}
	else if (ft_strncmp(ext, extension, 5))
	{
		ft_putstr_fd("Error\nWrong extension\n", 2);
		exit(1);
	}
}

void	file_reader(t_game *game, int fd)//not done
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (line[0] != '\n')
		{
			if (lines_pars(game, line))
			{
				map_parsing(game, line, fd);
				return ;
			}
		}
		free(line);
		line = get_next_line(fd);
	}
}