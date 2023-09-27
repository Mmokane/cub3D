/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 02:36:24 by mmokane           #+#    #+#             */
/*   Updated: 2023/09/25 01:20:41 by mmokane          ###   ########.fr       */
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
<<<<<<< HEAD
void	exten_check(char *str, char *extension)//extension checker
=======

void	exten_check(char *str, char *extension)//done
>>>>>>> 707607f9e005e24c7be449f7e6f8bf919d1893bf
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

<<<<<<< HEAD
void	file_reader(t_game *game, int fd)//not done yet
=======
void	file_reader(t_game *game, int fd)//not done
>>>>>>> 707607f9e005e24c7be449f7e6f8bf919d1893bf
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (line[0] != '\n')
		{
			if (line_parsing(game, line))
			{
				map_parsing(game, line, fd);
				return ;
			}
		}
		free(line);
		line = get_next_line(fd);
	}
}