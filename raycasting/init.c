/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:29:04 by oubelhaj          #+#    #+#             */
/*   Updated: 2023/11/05 18:48:42 by oubelhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_ray(t_ray *ray, double ray_angle)
{
	ray->angle = ray_angle;
	ray->wall_hit_x = 0;
	ray->wall_hit_y = 0;
	ray->distance = 0;
	ray->is_down = (ray->angle >= 0 && ray->angle <= M_PI);
	ray->is_right = (ray->angle <= M_PI_2 || ray->angle >= 1.5 * M_PI);
	ray->is_up = !ray->is_down;
	ray->is_left = !ray->is_right;
	ray->dist_proj_plane = 0;
	ray->wall_strip_h = 0;
	ray->wall_cords.bot_pix = 0;
	ray->wall_cords.top_pix = 0;
	ray->hit_vert = 0;
}

void	init_player_data(t_data *data)
{
	data->player->straf_direction = 0;
	data->player->fov = 60 * (M_PI / 180);
	data->player->walk_direction = 0;
	data->player->turn_direction = 0;
	data->player->move_speed = 5.0;
	data->player->rotation_speed = 2.5 * (M_PI / 180);
	data->player->rot_angle = 0;
	if (data->player->dir == 'N')
		data->player->rot_angle = 1.5 * M_PI;
	else if (data->player->dir == 'S')
		data->player->rot_angle = M_PI / 2;
	else if (data->player->dir == 'W')
		data->player->rot_angle = M_PI;
}

void	init_mlx_data(t_data *data)
{
	data->mlx = mlx_init();
	data->map_width = data->map->w * TILE_SIZE;
	data->map_height = data->map->h * TILE_SIZE;
	data->num_of_rays = WIDTH;
	data->mlx_win = mlx_new_window(data->mlx, WIDTH,
			HEIGHT, "cub3D");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
}
