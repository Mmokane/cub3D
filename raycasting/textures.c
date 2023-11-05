/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:30:29 by oubelhaj          #+#    #+#             */
/*   Updated: 2023/11/05 22:14:03 by oubelhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	get_textures(t_ray *ray)
{
	if (ray->hit_vert && ray->is_left)
		return (WE);
	else if (ray->hit_vert && ray->is_right)
		return (EA);
	else if (!ray->hit_vert && ray->is_up)
		return (NO);
	return (SO);
}

int	get_texture_pixel_color(int x, int y, t_data *data, int n)
{
	int	offset;
	int	color;

	if (x < 0 || y < 0 || x > TEXTURE_WIDTH || y > TEXTURE_HEIGHT)
		return (0);
	offset = (y * TEXTURE_WIDTH + x) * (data->tex[n].bits_per_pixel / 8);
	if (offset >= 0 && offset < TEXTURE_WIDTH * TEXTURE_HEIGHT
		* (data->tex[n].bits_per_pixel / 8))
		color = *(int *)(data->tex[n].addr + offset);
	else
		color = 0x000000;
	return (color);
}

void	get_tex_addr(t_data *data)
{
	data->tex[EA].addr = mlx_get_data_addr(data->tex[EA].img,
			&data->tex[EA].bits_per_pixel, &data->tex[EA].line_length,
			&data->tex[EA].endian);
	data->tex[NO].addr = mlx_get_data_addr(data->tex[NO].img,
			&data->tex[NO].bits_per_pixel, &data->tex[NO].line_length,
			&data->tex[NO].endian);
	data->tex[SO].addr = mlx_get_data_addr(data->tex[SO].img,
			&data->tex[SO].bits_per_pixel, &data->tex[SO].line_length,
			&data->tex[SO].endian);
	data->tex[WE].addr = mlx_get_data_addr(data->tex[WE].img,
			&data->tex[WE].bits_per_pixel, &data->tex[WE].line_length,
			&data->tex[WE].endian);
}

void	get_tex_img(t_data *data)
{
	data->tex[EA].img = mlx_xpm_file_to_image(data->mlx,
			data->map->ea, &data->tex[EA].width,
			&data->tex[EA].height);
	data->tex[NO].img = mlx_xpm_file_to_image(data->mlx,
			data->map->no, &data->tex[NO].width,
			&data->tex[NO].height);
	data->tex[SO].img = mlx_xpm_file_to_image(data->mlx,
			data->map->so, &data->tex[SO].width,
			&data->tex[SO].height);
	data->tex[WE].img = mlx_xpm_file_to_image(data->mlx,
			data->map->we, &data->tex[WE].width,
			&data->tex[WE].height);
}

void	load_textures(t_data *data)
{
	data->tex = malloc(sizeof(t_textures) * 4);
	get_tex_img(data);
	get_tex_addr(data);
}
