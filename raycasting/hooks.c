/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:28:12 by oubelhaj          #+#    #+#             */
/*   Updated: 2023/11/05 17:16:29 by oubelhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	key_press(int keycode, t_data *data)
{
	if (keycode == W_KEY)
		data->player->walk_direction = 1;
	else if (keycode == S_KEY)
		data->player->walk_direction = -1;
	else if (keycode == A_KEY)
		data->player->straf_direction = -1;
	else if (keycode == D_KEY)
		data->player->straf_direction = 1;
	else if (keycode == LEFT)
		data->player->turn_direction = -1;
	else if (keycode == RIGHT)
		data->player->turn_direction = 1;
	else if (keycode == ESC_KEY)
		close_game(data);
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == W_KEY)
		data->player->walk_direction = 0;
	else if (keycode == S_KEY)
		data->player->walk_direction = 0;
	else if (keycode == A_KEY)
	{
		data->player->straf_direction = 0;
		data->player->turn_direction = 0;
	}
	else if (keycode == D_KEY)
	{
		data->player->straf_direction = 0;
		data->player->turn_direction = 0;
	}
	else if (keycode == LEFT || keycode == RIGHT)
		data->player->turn_direction = 0;
	return (0);
}

void	free_data(t_data *data)
{
	int	i;

	i = 0;
	while (data->map->map[i])
		free(data->map->map[i++]);
	free(data->map->map);
	free(data->tex);
	free(data->player);
	free(data->map->ea);
	free(data->map->no);
	free(data->map->so);
	free(data->map->we);
	free(data->map);
	free(data);
}

int	close_game(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->mlx_win);
	free_data(data);
	// system("leaks cub3D");
	exit(0);
}
