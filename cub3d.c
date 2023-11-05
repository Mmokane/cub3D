/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 01:05:28 by mmokane           #+#    #+#             */
/*   Updated: 2023/11/05 21:50:52 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	update_player_position(t_data *data)
{
	double	move_step;
	double	straf_step;
	double	new_x;
	double	new_y;

	move_step = 0;
	straf_step = 0;
	data->player->rot_angle += data->player->turn_direction
		* data->player->rotation_speed;
	data->player->rot_angle = norm_angle(data->player->rot_angle);
	move_step = data->player->walk_direction * data->player->move_speed;
	straf_step = data->player->straf_direction * data->player->move_speed;
	new_x = data->player->x + cos(data->player->rot_angle) * move_step;
	new_y = data->player->y + sin(data->player->rot_angle) * move_step;
	new_x += cos(data->player->rot_angle + M_PI_2) * straf_step;
	new_y += sin(data->player->rot_angle + M_PI_2) * straf_step;
	if (!is_wall(new_x + RADIUS, new_y, data)
		&& !is_wall(new_x - RADIUS, new_y, data)
		&& !is_wall(new_x, new_y + RADIUS, data)
		&& !is_wall(new_x, new_y - RADIUS, data))
	{
		data->player->x = new_x;
		data->player->y = new_y;
	}
}

int	game_loop(t_data *data)
{
	update_player_position(data);
	cast_rays(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	my_mlx_clear_image(data);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (ac != 2)
		ft_putstr_fd2("Error: Invalid number of arguments\n", 2);
	parsing(data, av[1]);
	init_mlx_data(data);
	init_player_data(data);
	load_textures(data);
	mlx_hook(data->mlx_win, 2, 0, key_press, data);
	mlx_hook(data->mlx_win, 3, 0, key_release, data);
	mlx_hook(data->mlx_win, 17, 0, close_game, data);
	mlx_loop_hook(data->mlx, game_loop, data);
	mlx_loop(data->mlx);
	return (0);
}
