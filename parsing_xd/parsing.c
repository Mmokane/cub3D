/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 04:01:37 by mmokane           #+#    #+#             */
/*   Updated: 2023/10/04 04:24:38 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	**map_create(char **str, char *arg)
{
	int i;
	int args_len;
	char **args;
	
	if (str[0] || !str)
	{
		args = (char **)malloc(sizeof(char *) * 2);
		args[0] = ft_strdup(arg);
		args[1] = NULL;
		return(args);
	}
	args_len = 0;
	while(str[args_len])
		args_len++;
	args_len++;
	args = (char **)malloc(sizeof(char *) * (args_len + 1));
	i = 0;
	while (str[i])
	{
		args[i] = ft_strdup(str[i]);
		i++;
	}
	args[i] = ft_strdup(arg);
	args[i + 1] = NULL;
	return (args);
}
void	parsing(t_game *game, char *str)
{
	int fd;

	exten_check(str, ".cub");
	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nCan't open file\n", 2);
		exit(1);
	}
	init(game);//need to init data here :3 dont forget
	file_reader(game, fd);
	final_check(game, game->map->map);
	check_sides(game->map->map);
}

