/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_get_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 18:15:53 by emlicame          #+#    #+#             */
/*   Updated: 2023/01/04 20:25:31 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static mlx_image_t	*st_get_image(mlx_t *mlx, char *png)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png(png);
	if (texture == NULL)
		error_exit("Fail to read png file.");
	img = mlx_texture_to_image(mlx, texture);
	mlx_delete_texture(texture);
	if (img == NULL)
		error_exit("Fail to render image.");
	return (img);
}

void	sl_get_images(t_data *data)
{
	data->img.wall = st_get_image(data->mlx, "images/tile.png");
	data->img.pc = st_get_image(data->mlx, "images/fat_chef.png");
}
