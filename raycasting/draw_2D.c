/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2D.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:12:53 by oubelhaj          #+#    #+#             */
/*   Updated: 2023/11/03 16:47:02 by oubelhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_square(t_point point, int len, t_data *data, int draw_borders)
{
	int	i;
	int	j;

	j = 0;
	while (j < len)
	{
		i = 0;
		while (i < len)
		{
			if (draw_borders && (i == len - 1 || j == len - 1))
				my_mlx_pixel_put(data, i + point.x, j + point.y, 0x000000);
			else
				my_mlx_pixel_put(data, i + point.x, j + point.y, point.color);
			i++;
		}
		j++;
	}
}

void	draw_2d_map(t_data *data)
{
	int			i;
	int			j;
	t_point		point;

	i = 0;
	while (i < data->map->h)
	{
		j = 0;
		while (j < data->map->w && j < (int)ft_strlen(data->map->map[i]))
		{
			point.x = j * TILE_SIZE;
			point.y = i * TILE_SIZE;
			point.color = 0x053B50;
			if (data->map->map[i][j] == '1')
				point.color = 0xEEEEEE;
			draw_square(point, TILE_SIZE, data, 1);
			j++;
		}
		i++;
	}
}

void render_player(t_data *data)
{
	int		i;
	int		j;
	int		line_x;
	int		line_y;
	int		line_length;
	int		player_size;

	player_size = TILE_SIZE / 6;

	// Render a rectangle to represent the player
	i = 0;
	while (i < player_size)
	{
		j = 0;
		while (j < player_size)
		{
			my_mlx_pixel_put(data, data->player->x + i, data->player->y + j, 0xFF0000);
			j++;
		}
		i++;
	}
	// Draw a line from the player to represent the player's direction
	line_length = TILE_SIZE;
	// printf("rot_angle : %f\n", data->player->rot_angle);
	i = 0;
	while (i < line_length)
	{
		line_x = data->player->x + player_size / 2 + i * cos(data->player->rot_angle);
		line_y = data->player->y + player_size / 2 + i * sin(data->player->rot_angle);
		my_mlx_pixel_put(data, line_x, line_y, 0x00FF00);
		i++;
	}
}
