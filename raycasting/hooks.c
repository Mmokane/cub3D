/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:28:12 by oubelhaj          #+#    #+#             */
/*   Updated: 2023/11/03 17:24:25 by oubelhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	key_press(int keycode, t_data *data)
{
	if (keycode == W_KEY)
		data->player->walk_direction = 1;
	else if (keycode == S_KEY)
		data->player->walk_direction = -1;
	else if (keycode == A_KEY || keycode == LEFT)
		data->player->turn_direction = -1;
	else if (keycode == D_KEY || keycode == RIGHT)
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
	else if (keycode == A_KEY || keycode == LEFT)
		data->player->turn_direction = 0;
	else if (keycode == D_KEY || keycode == RIGHT)
		data->player->turn_direction = 0;
	return (0);
}

int	close_game(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit(0);
}
