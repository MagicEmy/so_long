/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapfile_validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:46:26 by emlicame          #+#    #+#             */
/*   Updated: 2023/01/11 18:06:49 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_if_frame_is_wall(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[0][i])
		if (data->map[0][i++] != '1')
			error_exit(ERROR_TOP_WALL);
	i = 0;
	while (data->map[data->height - 1][i])
		if (data->map[data->height - 1][i++] != '1')
			error_exit(ERROR_BOTTOM_WALL);
	i = 0;
	while (data->map[i])
	{
		if (*data->map[i] != '1' || data->map[i][data->width - 1] != '1')
			error_exit(ERROR_SIDE_WALL);
		i++;
	}
}

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
			error_exit(ERROR_BAD_MAP_SHAPE);
		i++;
	}
}
	// if (data->height == data->width)
	// 	error_exit("Map is not rectangular.");

void	check_map_syntax(char *mapline, t_data *data)
{
	int		i;

	i = 0;
	while (mapline[i])
	{
		if (!ft_strchr("01CPE\n", mapline[i]))
			error_exit(ERROR_INVALID_CHAR);
		if (mapline[i] == 'C')
			data->c++;
		else if (mapline[i] == 'P')
			data->p++;
		else if (mapline[i] == 'E')
			data->e++;
		i++;
	}
	if (data->c < 1)
		error_exit(ERROR_COLLECT_COUNT);
	if (data->p != 1)
		error_exit(ERROR_PLAYER_COUNT);
	if (data->e != 1)
		error_exit(ERROR_EXIT_COUNT);
}

void	check_extension(char *argv)
{
	int	len;

	len = ft_strlen(argv);
	if (ft_strncmp(&argv[len - 4], ".ber", 4) != 0)
		error_exit(ERROR_MAP_EXTENSION);
}

void	mapfile_validation(char *argv, t_data *data)
{
	char	*map_line;
	int		i;

	i = 0;
	check_extension(argv);
	map_line = get_line(argv);
	if (ft_strncmp(map_line, "", 1) == 0)
		error_exit(ERROR_EMPTY_FILE);
	check_map_syntax(map_line, data);
	data->map = ft_split(map_line, '\n');
	free(map_line);
	if (!data->map)
		error_exit(ERROR_MALLOC);
	check_if_rectangle(data);
	check_if_frame_is_wall(data);
	player_start_pos(data);
}
