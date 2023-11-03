/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:30:29 by oubelhaj          #+#    #+#             */
/*   Updated: 2023/11/03 17:12:21 by oubelhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	get_textures(t_ray *ray)
{
	if (ray->is_down)
		return (SO);
	else if (ray->is_up)
		return (NO);
	else if (ray->is_left)
		return (WE);
	return (EA);
}

int get_texture_pixel_color(int x, int y, t_data *data)
{
    int color;

    if (x < 0 || y < 0 || x > TEXTURE_WIDTH || y > TEXTURE_HEIGHT)
        return (0); // error
    // Calculate the color offset in the image data based on the (x, y) coordinates
    // printf("%d\n", data->textures[0].bits_per_pixel / 8);
    // exit(1);
    int offset = (y * TEXTURE_WIDTH + x) * (data->textures[0].bits_per_pixel / 8);

    // Read the color from the image data
    if (offset >= 0 && offset < TEXTURE_WIDTH * TEXTURE_HEIGHT * (data->textures[0].bits_per_pixel / 8))
    {
        color = *(int *)(data->textures[0].addr + offset);
    }
    else
    {
        // Return a default color if the (x, y) coordinates are out of bounds
        color = 0x000000; // Default to black
    }

    return color;
}

void	load_textures(t_data *data)
{
	data->textures = malloc(sizeof(t_textures) * 4);

	data->textures[EA].img = mlx_xpm_file_to_image(data->mlx, "/Users/oubelhaj/Desktop/mmokane/textures/Stone1.xpm", &data->textures[EA].width, &data->textures[EA].height);
	// data->textures[NO].img = mlx_xpm_file_to_image(data->mlx, "../textures/Stone2.xpm", &data->textures[NO].width, &data->textures[NO].height);
	// data->textures[SO].img = mlx_xpm_file_to_image(data->mlx, "../textures/Stone2.xpm", &data->textures[SO].width, &data->textures[SO].height);
	// data->textures[WE].img = mlx_xpm_file_to_image(data->mlx, "../textures/Stone2.xpm", &data->textures[WE].width, &data->textures[WE].height);

	data->textures[EA].addr = mlx_get_data_addr(data->textures[EA].img, &data->textures[EA].bits_per_pixel, &data->textures[EA].line_length, &data->textures[EA].endian);
	// data->textures[NO].addr = mlx_get_data_addr(data->textures[NO].img, &data->textures[NO].bits_per_pixel, &data->textures[NO].line_length, &data->textures[NO].endian);
	// data->textures[SO].addr = mlx_get_data_addr(data->textures[SO].img, &data->textures[SO].bits_per_pixel, &data->textures[SO].line_length, &data->textures[SO].endian);
	// data->textures[WE].addr = mlx_get_data_addr(data->textures[WE].img, &data->textures[WE].bits_per_pixel, &data->textures[WE].line_length, &data->textures[WE].endian);
}