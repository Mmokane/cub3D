/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 01:05:28 by mmokane           #+#    #+#             */
/*   Updated: 2023/10/07 11:56:54 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int main(int ac, char **av)
{
	t_game *game;

	game = (t_game *)malloc(sizeof(t_game));
	
	if (ac != 2)
		ft_putstr_fd2("Error: Invalid number of arguments\n", 2);
	parsing(game, av[1]);

}