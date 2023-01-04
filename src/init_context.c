/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_context.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/09 18:15:53 by emlicame      #+#    #+#                 */
/*   Updated: 2022/12/21 11:32:46 by emanuela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*create_image(char *path, t_data *data)
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

void	init_context(t_data *data)
{
	mlx_image_t	*tile_img;

	tile_img = create_image("images/tile.png", data);
	if (tile_img == NULL)
		exit(EXIT_FAILURE);
	data->tile = tile_img;
	mlx_image_to_window(data->mlx, tile_img, 64, 64); // z = 0
	mlx_image_to_window(data->mlx, tile_img, 0, 0);   // z = 1
}
