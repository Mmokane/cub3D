/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 04:29:36 by mmokane           #+#    #+#             */
/*   Updated: 2023/09/25 01:20:16 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	map_tokens(char *name)//check name // done
{
	if (!ft_strncmp(name, "NO", 3))
		return (T_NO);
	else if (!ft_strncmp(name, "SO", 3))
		return (T_SO);
	else if (!ft_strncmp(name, "WE", 3))
		return (T_WE);
	else if (!ft_strncmp(name, "EA", 3))
		return (T_EA);
	else if (!ft_strncmp(name, "F", 2))
		return (T_F);
	else if (!ft_strncmp(name, "C", 2))
		return (T_C);
	else
		return (T_Error);
}

int	line_parsing(t_game *game, char *line)//line_parsing//not yet
{
	int		i;
	int		j;
	int		token;
	char	*name;

	i = 0;
	if (map_check(line))//is_map
		return (1);
	space_skipper(line, &i);
	j = i;
	while (line[i] && line[i] != ' ' && line[i] != '\t')
		i++;
	name = ft_substr(line, j, i - j);
	token = map_tokens(name);//check_name
	if (token == T_Error)
	{
		write(2, "Invalid token\n", ft_strlen("Invalid token\n"));
		exit(1);
	}
	else if (token == T_F || token == T_C)
		color_parsing(cub, ft_strtrim(line, "\n"), token, i);//make them
	else
		texture_parsing(cub, ft_strtrim(line, "\n"), token, i);//make them
	free(name);
	return (0);
}

void	check_sides(char **map)//map_borders//done
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (map[0][j] == ' ')
		j++;
	while (map[0][j] == '1')
		j++;
	if (map[0][j] != '1' && map[0][j] != '\0' && map[0][j] != ' ')
	{
		write(2, "Error: Invalid map\n", 19);
		exit(1);
	}
	while (map[i])
	{
		if (map[i][0] == '\0' || map[i][0] == '\t'
			|| map[i][0] == '\n')
		{
			write(2, "Error: Invalid map\n", 19);
			exit(1);
		}
		i++;
	}
}