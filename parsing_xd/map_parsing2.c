/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:57:39 by mmokane           #+#    #+#             */
/*   Updated: 2023/10/11 16:13:19 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	player_exist(char c)
{
	if (c == 'W' || c == 'N' || c == 'E' || c == 'S')
		return (1);
	return (0);
}

int	lines_value(t_game *game)
{
	if (game->map->we == NULL || game->map->no == NULL
		|| game->map->ea == NULL || game->map->so == NULL
		|| game->map->f == -1 || game->map->c == -1)
		ft_putstr_fd2("Error at line value\n", 2);
	return (0);
}

int	color_value(char *line, int *i)
{
	int		j;
	int		x;
	int		color;
	char	*rgb;

	if (line[*i] == ',')
		(*i)++;
	while (line[*i] && line[*i] == ' ')
		(*i)++;
	j = *i;
	while (line[*i] && line[*i] != ',' && line[*i] != ' ')
		(*i)++;
	rgb = ft_substr(line, j, *i - j);
	x = -1;
	while (rgb[++x])
		if (!ft_isdigit(rgb[x]))
			ft_putstr_fd2("Error at color value 'digit'\n", 2);
	color = ft_atoi(rgb);
	if (!rgb[0])
		ft_putstr_fd2("Error f rgb hhhh \n", 2);
	free(rgb);
	if (color < 0 || color > 255)
		ft_putstr_fd2("Error at color value 'range'\n", 2);
	return (color);
}

void	color_pars(t_game *game, char *line, int token, int i)
{
	int		color[3];
	int		n;

	n = 0;
	while (n < 3)
	{
		space_skipper(line, &i);
		color[n] = color_value(line, &i);
		n++;
	}
	if (line[i])
		ft_putstr_fd2("Error at color value\n", 2);
	check_nums(line);
	if (token == T_F && game->map->f == 0)
		game->map->f = (color[0] << 16) + (color[1] << 8) + color[2];
	else if (token == T_C && game->map->c == 0)
		game->map->c = (color[0] << 16) + (color[1] << 8) + color[2];
	else
		ft_putstr_fd2("Error duplicate rgb hhhh \n", 2);
	free(line);
}
