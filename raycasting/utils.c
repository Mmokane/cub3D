/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:29:13 by oubelhaj          #+#    #+#             */
/*   Updated: 2023/11/04 12:10:18 by oubelhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

double	norm_angle(double angle)
{
	angle = fmod(angle, 2 * M_PI);
	if (angle < 0)
		angle += 2 * M_PI;
	return (angle);
}

int	is_wall(double x, double y, t_data *data)
{
	int		map_x;
	int		map_y;

	if (x < 0 || x > data->map_width || y < 0 || y > data->map_height)
		return (1);
	map_x = (int)x / TILE_SIZE;
	map_y = (int)y / TILE_SIZE;
	if (map_x >= (int)ft_strlen(data->map->map[map_y]))
		return (1);
	if (data->map->map[map_y][map_x] == '1')
		return (1);
	return (0);
}

void	my_mlx_clear_image(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			my_mlx_pixel_put(data, i, j, 0);
			j++;
		}
		i++;
	}
}

double	get_distance(int px, int py, int hx, int hy)
{
	return (sqrt((hx - px) * (hx - px) + (hy - py) * (hy - py)));
}
