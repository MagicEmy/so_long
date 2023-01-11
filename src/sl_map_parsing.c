/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 18:15:53 by emlicame          #+#    #+#             */
/*   Updated: 2023/01/11 18:14:37 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	frontier_check(t_data *data, char **map, int x, int y)
{
	static int	collectibles;

	if (map[x][y] == '1')
		return ;
	if (map[x][y] == 'E')
	{
		data->to_exit = true;
		return ;
	}
	if (map[x][y] == 'C')
	{
		collectibles += 1;
		if (collectibles == data->c)
		{
			data->to_collect = true;
			return ;
		}	
	}
	map[x][y] = '1';
	frontier_check(data, map, x + 1, y);
	frontier_check(data, map, x, y + 1);
	frontier_check(data, map, x - 1, y);
	frontier_check(data, map, x, y - 1);
}

char	**copy_map(t_data *data)
{
	char	**copy_map;
	int		i;

	i = 0;
	copy_map = (char **)malloc(sizeof(char *) * (data->height + 1));
	if (!copy_map)
		error_exit(ERROR_MALLOC);
	while (data->map[i])
	{
		copy_map[i] = ft_strdup(data->map[i]);
		i++;
	}
	copy_map[i] = NULL;
	return (copy_map);
}

void	player_start_pos(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map[y])
	{
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'P')
			{
				data->pc_x = x;
				data->pc_y = y;
				return ;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	map_drawing(t_data *data)
{
	char	**copy;
	int		i;

	i = 0;
	copy = NULL;
	sl_get_images(data);
	sl_images_to_window(data);
	copy = copy_map(data);
	frontier_check(data, copy, data->pc_y, data->pc_x);
	if (!data->to_exit || !data->to_collect)
		error_exit(ERROR_INVALID_MAP);
	sl_free_mem(&copy);
}
