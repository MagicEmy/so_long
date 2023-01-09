/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:33:42 by emlicame          #+#    #+#             */
/*   Updated: 2023/01/09 19:22:07 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_exit(char *text)
{
	ft_putstr_fd("\033[0;31mERROR\n", 2);
	ft_putendl_fd(text, 2);
	exit(EXIT_FAILURE);
}

void	sl_free_mem(char ***array)
{
	int	i;

	i = 0;
	if (!*array)
		return ;
	while ((*array)[i])
	{
		free((*array)[i]);
		(*array)[i] = NULL;
		i++;
	}
	free(*array);
	*array = NULL;
}

t_data	*data_init(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		error_exit("Memory allocation failed.");
	data->width = 0;
	data->height = 0;
	data->c = 0;
	data->p = 0;
	data->e = 0;
	data->pc_x = 0;
	data->pc_y = 0;
	data->to_exit = false;
	data->to_collect = false;
	data->map = NULL;
	return (data);
}

int32_t	main(int argc, char **argv)
{
	mlx_t		*mlx;
	t_data		*data;

	data = NULL;
	if (argc != 2)
		error_exit("Arguments are not valid.");
	data = data_init();
	mapfile_validation(argv[1], data);
	mlx = mlx_init(TILE_SIZE * data->width, TILE_SIZE * data->height, \
	"Spacewalk", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	data->mlx = mlx;
	map_drawing(data);
	mlx_key_hook(mlx, key_hook, data);
	mlx_loop(mlx);
	sl_free_mem(&data->map);
	mlx_terminate(mlx);
	free(data);
	return (EXIT_SUCCESS);
}
	// while (1)
	// 	;
	// mlx = mlx_init(len_str * TILE_+SIZE, nr_nl * TILE_SIZE, "MLX42", false);