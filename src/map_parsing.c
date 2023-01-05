/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 18:15:53 by emlicame          #+#    #+#             */
/*   Updated: 2023/01/05 17:11:59 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_if_frame_is_wall(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[0][i])
	{
		if (data->map[0][i] != '1')
			error_exit("Invalid char in top frame.");
		i++;
	}
	i = 0;
	while (data->map[data->height - 1][i])
	{
		if (data->map[data->height - 1][i] != '1')
			error_exit("Invalid char in low frame.");
		i++;
	}
}

	// printf ("top %s\n", data->map[0]);
	// printf ("lowline %s\n", data->map[data->height - 1]);

void	check_if_rectangle(t_data *data)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (data->map[data->height])
		data->height++;
	data->width = ft_strlen(*data->map);
	while (data->map[i])
	{
		len = ft_strlen(data->map[i]);
		if (len != data->width)
			error_exit("Map has not a regular shape.");
		i++;
	}
	if (data->height == data->width)
		error_exit("Map is not rectangular.");
}
