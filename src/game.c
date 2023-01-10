/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 11:34:37 by emanuela          #+#    #+#             */
/*   Updated: 2023/01/10 20:27:54 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	print_moves(t_data *data)
{
	char	*movements;

	data->movements++;
	movements = ft_itoa(data->movements);
	ft_putendl_fd(movements, 1);
	free (movements);
}

static int	is_wall(t_data *data, int x, int y)
{
	int	new_x;
	int	new_y;

	new_x = (data->img.pc->instances[0].x / TILE_SIZE) + x;
	new_y = (data->img.pc->instances[0].y / TILE_SIZE) + y;
	if (data->map[new_y][new_x] == '1')
		return (1);
	print_moves(data);
	return (0);
}

static void	check_exit(t_data *data)
{
	if (data->coll_increment == data->c)
	{
		data->img.exit->instances[0].enabled = false;
		mlx_image_to_window(data->mlx, data->img.sky, \
			data->img.pc->instances[0].x, data->img.pc->instances[0].y);
		mlx_put_string(data->mlx, "Ruler of the Universe!", \
		data->img.pc->instances[0].x, data->img.pc->instances[0].y + 15);
		return ;
	}
	else
	{
		mlx_put_string(data->mlx, "Don't", data->img.pc->instances[0].x \
		+ 5, data->img.pc->instances[0].y + 15);
		mlx_put_string(data->mlx, "panic!", data->img.pc->instances[0].x \
		+ 5, data->img.pc->instances[0].y + 30);
		return ;
	}
}

static void	check_collectibles(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->c)
	{
		if (data->img.pc->instances[0].x == data->img.collect->instances[i].x \
		&& data->img.pc->instances[0].y == data->img.collect->instances[i].y && \
		data->img.collect->instances[i].enabled)
		{
			data->img.collect->instances[i].enabled = false;
			data->coll_increment++;
			return ;
		}
		i++;
	}
}

void	sl_key_hook(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keydata.action != MLX_PRESS)
		return ;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(data->mlx);
	if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT) \
		&& !is_wall(data, 1, 0))
		data->img.pc->instances[0].x += TILE_SIZE;
	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT) \
		&& !is_wall(data, -1, 0))
		data->img.pc->instances[0].x -= TILE_SIZE;
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP) \
		&& !is_wall(data, 0, -1))
		data->img.pc->instances[0].y -= TILE_SIZE;
	if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN) \
		&& !is_wall(data, 0, 1))
		data->img.pc->instances[0].y += TILE_SIZE;
	if (data->img.pc->instances[0].x == data->img.exit->instances[0].x \
		&& data->img.pc->instances[0].y == data->img.exit->instances[0].y)
		return (check_exit(data));
	check_collectibles(data);
}

	// && !is_wall(data, 1, 0))

	// x = data->map[(y + TILE_SIZE) / TILE_SIZE][x / TILE_SIZE] == '1'
	// y = y / TILE_SIZE
	// 