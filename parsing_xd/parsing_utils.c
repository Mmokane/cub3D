/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moskir <moskir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:05:08 by mmokane           #+#    #+#             */
/*   Updated: 2023/10/24 02:40:51 by moskir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	space_skipper(char *s, int *i)
{
	while (s[*i] && (s[*i] == ' ' || s[*i] == '\t'))
		(*i)++;
}

void	check_nums(char *line)
{
	int		i;
	char	**j;

	i = 0;
	j = ft_split(line, ',');
	if (!j)
		ft_putstr_fd2("Error\n", 2);
	while (j[i])
		i++;
	if (i != 3)
		ft_putstr_fd2("Error\n", 2);
	ft_free(j);
}

void	data_init(t_game *game)
{
	game->map->we = NULL;
	game->map->no = NULL;
	game->map->ea = NULL;
	game->map->so = NULL;
	game->map->dr = NULL;
	game->map->f = 0;
	game->map->h = 0;
	game->map->w = 0;
	game->map->c = 0;
	game->player->x = 0;
	game->player->y = 0;
}

void	init(t_game *game)
{
	if (!game)
		ft_putstr_fd2("Error (init)\n", 2);
	game->player = (t_player *)malloc(sizeof(t_player));
	game->map = (t_map *)malloc(sizeof(t_map));
	game->map->map = ft_calloc(1, sizeof(char *));
	if (!game->map->map || !game->map)
		ft_putstr_fd2("Error (init)\n", 2);
	data_init(game);
}
