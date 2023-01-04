/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: emanuela <emanuela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/26 11:34:37 by emanuela      #+#    #+#                 */
/*   Updated: 2022/12/26 11:35:01 by emanuela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = (t_data *)param;
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
