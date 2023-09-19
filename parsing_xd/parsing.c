/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 04:01:37 by mmokane           #+#    #+#             */
/*   Updated: 2023/09/19 04:13:05 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
	//need to init data here :3 dont forget
	file_reader(t_game *game, fd);	
}