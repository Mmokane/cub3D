/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 04:27:19 by mmokane           #+#    #+#             */
/*   Updated: 2023/10/07 09:46:43 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	space_skipper(char *s, int *i)
{
	while (s[*i] && (s[*i] == ' ' || s[*i] == '\t'))
		(*i)++;
}

void	check_nums(char *line)// check_lenght
{
	int		i;
	char	**f;

	i = 0;
	f = ft_split(line, ',');
	if (!f)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	while (f[i])
		i++;
	if (i != 3)
		ft_putstr_fd("Error\n", 2);
	// free_loop(f);
}
void	data_init(t_game *game)
{
	game->map->we = NULL;
	game->map->no = NULL;
	game->map->ea = NULL;
	game->map->so = NULL;
	game->map->dr = NULL;
	game->map->F = 0;
	game->map->C = 0;
}

void	init(t_game *game)
{
	if (!game)
	{
		write(2, "Error\n", 6);
		exit(1);
	}	
	game->map = (t_map *)malloc(sizeof(t_map));
	game->map->map = ft_calloc(1, sizeof(char *));// recheck for leaks "calloc"
	if (!game->map->map || !game->map)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	data_init(game);
}
