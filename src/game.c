/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 11:34:37 by emanuela          #+#    #+#             */
/*   Updated: 2023/01/08 19:21:42 by emlicame         ###   ########.fr       */
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
	if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT) && \
	keydata.action == MLX_PRESS)
		data->img.pc->instances[0].x += TILE_SIZE;
	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT) && \
	keydata.action == MLX_PRESS)
		data->img.pc->instances[0].x -= TILE_SIZE;
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP) && \
	keydata.action == MLX_PRESS)
		data->img.pc->instances[0].y -= TILE_SIZE;
	if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN) && \
	keydata.action == MLX_PRESS)
		data->img.pc->instances[0].y += TILE_SIZE;
}
/*
	if (data->tile->instances[0].x == data->tile->instances[1].x && \
	data->tile->instances[0].y == data->tile->instances[1].y)
		data->tile->instances[1].enabled = false;
*/
