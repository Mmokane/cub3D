/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:30:04 by oubelhaj          #+#    #+#             */
/*   Updated: 2023/11/06 00:28:19 by oubelhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	setup_horz_intersec_params(t_ray *ray, t_data *data, t_cords *horz)
{
	double	arc_tan;

	arc_tan = 1 / tan(ray->angle);
	if (ray->is_up)
	{
		horz->y_intercept = (int)data->player->y / TILE_SIZE * TILE_SIZE;
		horz->x_intercept = -(data->player->y - horz->y_intercept)
			* arc_tan + data->player->x;
		horz->y_step = -TILE_SIZE;
	}
	if (ray->is_down)
	{
		horz->y_intercept = (int)data->player->y / TILE_SIZE
			* TILE_SIZE + TILE_SIZE;
		horz->x_intercept = -(data->player->y - horz->y_intercept)
			* arc_tan + data->player->x;
		horz->y_step = TILE_SIZE;
	}
	horz->x_step = horz->y_step * arc_tan;
}

void	horizontal_intersections(t_ray *ray, t_data *data, t_cords *horz)
{
	setup_horz_intersec_params(ray, data, horz);
	while (horz->x_intercept >= 0 && horz->x_intercept <= WIDTH * TILE_SIZE
		&& horz->y_intercept >= 0 && horz->y_intercept <= HEIGHT * TILE_SIZE)
	{
		if (is_wall(horz->x_intercept, horz->y_intercept - (ray->is_up), data))
		{
			horz->hit = 1;
			return ;
		}
		else
		{
			horz->x_intercept += horz->x_step;
			horz->y_intercept += horz->y_step;
		}
	}
	horz->hit = 0;
}

void	setup_vert_intersec_params(t_ray *ray, t_data *data, t_cords *vert)
{
	double	arc_tan;

	arc_tan = -tan(ray->angle);
	if (ray->is_left)
	{
		vert->x_intercept = (int)data->player->x / TILE_SIZE * TILE_SIZE;
		vert->y_intercept = (data->player->x - vert->x_intercept)
			* arc_tan + data->player->y;
		vert->x_step = -TILE_SIZE;
	}
	if (ray->is_right)
	{
		vert->x_intercept = (int)data->player->x / TILE_SIZE
			* TILE_SIZE + TILE_SIZE;
		vert->y_intercept = (data->player->x - vert->x_intercept)
			* arc_tan + data->player->y;
		vert->x_step = TILE_SIZE;
	}
	vert->y_step = -vert->x_step * arc_tan;
}

void	vertical_intersections(t_ray *ray, t_data *data, t_cords *vert)
{
	setup_vert_intersec_params(ray, data, vert);
	while (vert->x_intercept >= 0 && vert->x_intercept <= WIDTH * TILE_SIZE
		&& vert->y_intercept >= 0 && vert->y_intercept <= HEIGHT * TILE_SIZE)
	{
		if (is_wall(vert->x_intercept - (ray->is_left), vert->y_intercept,
				data))
		{
			vert->hit = 1;
			return ;
		}
		else
		{
			vert->x_intercept += vert->x_step;
			vert->y_intercept += vert->y_step;
		}
	}
	vert->hit = 0;
}

void	distance_to_wall(t_ray *ray, t_data *data, t_cords horz, t_cords vert)
{
	double	horz_distance;
	double	vert_distance;

	horz_distance = INT_MAX;
	vert_distance = INT_MAX;
	if (horz.hit)
		horz_distance = get_distance(data->player->x, data->player->y,
				horz.x_intercept, horz.y_intercept);
	if (vert.hit)
		vert_distance = get_distance(data->player->x, data->player->y,
				vert.x_intercept, vert.y_intercept);
	if (horz_distance <= vert_distance)
	{
		ray->wall_hit_x = horz.x_intercept;
		ray->wall_hit_y = horz.y_intercept;
		ray->distance = horz_distance;
	}
	else
	{
		ray->wall_hit_x = vert.x_intercept;
		ray->wall_hit_y = vert.y_intercept;
		ray->distance = vert_distance;
		ray->hit_vert = 1;
	}
}
