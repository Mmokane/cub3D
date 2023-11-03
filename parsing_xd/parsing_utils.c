/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:05:08 by mmokane           #+#    #+#             */
/*   Updated: 2023/11/03 14:36:50 by oubelhaj         ###   ########.fr       */
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

void	data_init(t_data *data)
{
	data->map->we = NULL;
	data->map->no = NULL;
	data->map->ea = NULL;
	data->map->so = NULL;
	data->map->f = 0;
	data->map->h = 0;
	data->map->w = 0;
	data->map->c = 0;
	data->player->x = 0;
	data->player->y = 0;
}

void	init(t_data *data)
{
	if (!data)
		ft_putstr_fd2("Error (init)\n", 2);
	data->player = (t_player *)malloc(sizeof(t_player));
	data->map = (t_map *)malloc(sizeof(t_map));
	data->map->map = ft_calloc(1, sizeof(char *));
	if (!data->map->map || !data->map)
		ft_putstr_fd2("Error (init)\n", 2);
	data_init(data);
}
