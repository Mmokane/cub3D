/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:33:33 by oubelhaj          #+#    #+#             */
/*   Updated: 2023/11/04 19:24:25 by oubelhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	draw_wall_column(t_data *data, t_point vars, t_point tex, int n)
{
	int	color;
	int	distance_from_top;

	distance_from_top = 0;
	while (vars.y < data->rays[vars.x].wall_cords->bot_pix)
	{
		distance_from_top = vars.y + (data->rays[vars.x].wall_strip_h / 2)
			- (HEIGHT / 2);
		tex.y = distance_from_top * ((float)TEXTURE_HEIGHT
				/ data->rays[vars.x].wall_strip_h);
		color = get_texture_pixel_color(tex.x, tex.y, data, n);
		my_mlx_pixel_put(data, vars.x, vars.y, color);
		vars.y++;
	}
	return (vars.y);
}

void	draw_3d_ray(t_data *data, int i)
{
	int		j;
	int		n;
	t_point	vars;
	t_point	tex_offset;

	tex_offset.x = 0;
	tex_offset.y = 0;
	if (data->rays[i].hit_vert)
		tex_offset.x = (int)data->rays[i].wall_hit_y % TILE_SIZE;
	else
		tex_offset.x = (int)data->rays[i].wall_hit_x % TILE_SIZE;
	n = get_textures(&data->rays[i]);
	j = -1;
	while (++j < data->rays[i].wall_cords->top_pix)
		my_mlx_pixel_put(data, i, j, data->map->c);
	vars.x = i;
	vars.y = j;
	j = draw_wall_column(data, vars, tex_offset, n);
	while (j < HEIGHT)
	{
		my_mlx_pixel_put(data, i, j, data->map->f);
		j++;
	}
}

void	cast_rays(t_data *data)
{
	int			i;
	int			j;
	t_cords		horz;
	t_cords		vert;
	float		ray_angle;

	i = 0;
	j = 0;
	data->rays = malloc(sizeof(t_ray) * data->num_of_rays);
	ray_angle = data->player->rot_angle - (data->player->fov / 2);
	while (i < data->num_of_rays)
	{
		ray_angle = norm_angle(ray_angle);
		init_ray(&data->rays[i], ray_angle);
		horizontal_intersections(&data->rays[i], data, &horz);
		vertical_intersections(&data->rays[i], data, &vert);
		distance_to_wall(&data->rays[i], data, horz, vert);
		get_ray_data(data, &data->rays[i]);
		draw_3d_ray(data, i);
		ray_angle += data->player->fov / WIDTH;
		i++;
	}
}
