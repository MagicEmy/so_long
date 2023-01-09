/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 20:44:44 by emlicame          #+#    #+#             */
/*   Updated: 2023/01/09 17:57:37 by emlicame         ###   ########.fr       */
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
	data->img.wall = st_get_image(data->mlx, "images/asteroid.png");
	data->img.pc = st_get_image(data->mlx, "images/pc.png");
	data->img.sky = st_get_image(data->mlx, "images/sky.png");
	data->img.collect = st_get_image(data->mlx, "images/star_small.png");
	data->img.exit = st_get_image(data->mlx, "images/earth.png");
}

void	pc_and_exit_pos(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	mlx_image_to_window(data->mlx, data->img.pc, \
	TILE_SIZE * data->pc_x, TILE_SIZE * data->pc_y);
	while (data->map[y])
	{
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'E')
			{
				mlx_image_to_window(data->mlx, data->img.exit, \
				TILE_SIZE * x, TILE_SIZE * y);
				return ;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	sky_placement(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map[y])
	{
		while (data->map[y][x])
		{
			if (data->map[y][x] != '1')
			{
				mlx_image_to_window(data->mlx, data->img.sky, \
				TILE_SIZE * x, TILE_SIZE * y);
			}
			x++;
		}
		x = 0;
		y++;
	}
	pc_and_exit_pos(data);
}

void	sl_images_to_window(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	sky_placement(data);
	while (data->map[y])
	{
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1')
			{
				mlx_image_to_window(data->mlx, data->img.wall, \
				TILE_SIZE * x, TILE_SIZE * y);
			}
			else if (data->map[y][x] == 'C')
			{
				mlx_image_to_window(data->mlx, data->img.collect, \
				TILE_SIZE * x, TILE_SIZE * y);
			}
			x++;
		}
		x = 0;
		y++;
	}
}

/*
void	sl_images_to_window(t_data *data)
{
	int	i;

	i = 0;
	i = mlx_image_to_window(data->mlx, data->img.wall, \
	TILE_SIZE * 0, TILE_SIZE * 0); // z = 0
	// printf ("int %d\n", i);
	mlx_image_to_window(data->mlx, data->img.wall, \
	TILE_SIZE * 1, TILE_SIZE * 0);
	mlx_image_to_window(data->mlx, data->img.wall, \
	TILE_SIZE * 2, TILE_SIZE * 0);
	mlx_image_to_window(data->mlx, data->img.wall, \
	TILE_SIZE * 3, TILE_SIZE * 0);
	mlx_image_to_window(data->mlx, data->img.pc, \
	TILE_SIZE * data->pc_x, TILE_SIZE * data->pc_y);
}

//mlx_free_image(void* content)
*/