/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   first_main.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/23 19:33:42 by emlicame      #+#    #+#                 */
/*   Updated: 2022/09/26 18:07:46 by emlicame      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#define WIDTH 256
#define HEIGHT 256
#define TILE_SIZE 64
typedef struct s_info
{
	mlx_t			*mlx;
	mlx_image_t		*tile;
}	t_info;

mlx_image_t	*create_image(char *path, t_info *data)
{
	mlx_texture_t	*txt;
	mlx_image_t		*img;

	txt = mlx_load_png(path);
	if (txt == NULL)
		return (NULL);
	img = mlx_texture_to_image(data->mlx, txt);
	if (img == NULL)
		return (NULL);
	return (img);
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_info	*data;

	data = (t_info *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		//free txt, img
		mlx_close_window(data->mlx);
	}
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		data->tile->instances->x += TILE_SIZE;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		data->tile->instances->x -= TILE_SIZE;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		data->tile->instances->y -= TILE_SIZE;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		data->tile->instances->y += TILE_SIZE;
	if (data->tile->instances[0].x == data->tile->instances[1].x && \
	data->tile->instances[0].y == data->tile->instances[1].y)
		data->tile->instances[1].enabled = false;
}

int32_t	main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*tile_img;
	t_info		info;

	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	// mlx = mlx_init(len_str * TILE_+SIZE, nr_nl * TILE_SIZE, "MLX42", false!!);
	if (!mlx)
		exit(EXIT_FAILURE);
	info.mlx = mlx;
	tile_img = create_image("images/tile.png", &info);
	if (tile_img == NULL)
		return (EXIT_FAILURE);
	info.tile = tile_img;
	mlx_image_to_window(mlx, tile_img, 64, 64); // z = 0
	mlx_image_to_window(mlx, tile_img, 0, 0); // z = 1
	mlx_key_hook(mlx, key_hook, &info);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
