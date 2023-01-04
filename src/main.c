/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/23 19:33:42 by emlicame      #+#    #+#                 */
/*   Updated: 2022/12/26 13:12:02 by emanuela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_exit(char *text)
{
	ft_putstr_fd("Error\n", 2);
	ft_putendl_fd(text, 2);
	exit(EXIT_FAILURE);
}

void	ft_free_mem(char ***array)
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
	data->map = (char **)malloc(sizeof (char *) * 1);
	if (!data->map)
		error_exit("Memory allocation failed.");
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
	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	data->mlx = mlx;
	init_context(data);
	mlx_key_hook(mlx, key_hook, data);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	// ft_free_mem(&data->map);
	free(data);
	return (EXIT_SUCCESS);
}

	// mlx = mlx_init(len_str * TILE_+SIZE, nr_nl * TILE_SIZE, "MLX42", false!!);