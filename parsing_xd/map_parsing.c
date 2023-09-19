/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 04:29:36 by mmokane           #+#    #+#             */
/*   Updated: 2023/09/19 04:52:30 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
		{
		write(2, "Error: Invalid map\n", 19);
		exit(1);
		}
		i++;
	}
}