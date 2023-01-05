/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_images_to_window.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 20:01:33 by emlicame          #+#    #+#             */
/*   Updated: 2023/01/04 21:53:09 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	TILE_SIZE * 0, TILE_SIZE * 1);
}

//mlx_free_image(void* content)