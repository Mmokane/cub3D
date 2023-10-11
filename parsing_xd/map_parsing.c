/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 04:29:36 by mmokane           #+#    #+#             */
/*   Updated: 2023/10/11 16:29:55 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_putstr_fd2(char *s, int fd)
{
	if (s == 0)
		return ;
	write(fd, s, ft_strlen(s));
	exit (1);
}

int	map_tokens(char *arg)
{
	if (!ft_strncmp(arg, "NO", 3))
		return (T_NO);
	else if (!ft_strncmp(arg, "SO", 3))
		return (T_SO);
	else if (!ft_strncmp(arg, "WE", 3))
		return (T_WE);
	else if (!ft_strncmp(arg, "EA", 3))
		return (T_EA);
	else if (!ft_strncmp(arg, "F", 2))
		return (T_F);
	else if (!ft_strncmp(arg, "C", 2))
		return (T_C);
	else
		return (T_Error);
}

int	lines_pars(t_game *game, char *line)
{
	int		i;
	int		j;
	int		token;
	char	*arg;

	i = 0;
	if (map_check(line))
		return (1);
	space_skipper(line, &i);
	j = i;
	while (line[i] && line[i] != ' ' && line[i] != '\t')
		i++;
	arg = ft_substr(line, j, i - j);
	token = map_tokens(arg);
	if (token == T_Error)
		ft_putstr_fd2("Error: Invalid token\n", 2);
	else if (token == T_F || token == T_C)
		color_pars(game, ft_strtrim(line, "\n"), token, i);
	else
		texture_pars(game, ft_strtrim(line, "\n"), token, i);
	free(arg);
	return (0);
}

void	check_sides(char **map)
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
			ft_putstr_fd2("Error: Invalid map\n", 2);
		i++;
	}
}

void	texture_pars(t_game *game, char *line, int token, int i)
{
	char	*path;

	space_skipper(line, &i);
	path = ft_strdup(&line[i]);
	exten_check(path, ".xpm\0");
	if (token == T_EA && !game->map->ea)
		game->map->ea = path;
	else if (token == T_NO && !game->map->no)
		game->map->no = path;
	else if (token == T_WE && !game->map->we)
		game->map->we = path;
	else if (token == T_SO && !game->map->so)
		game->map->so = path;
	else
		ft_putstr_fd2("Error: wrong textures\n", 2);
	free(line);
}
