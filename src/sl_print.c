/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:37:11 by emlicame          #+#    #+#             */
/*   Updated: 2023/01/11 19:37:43 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_print_moves(t_data *data)
{
	char				*movements;
	static mlx_image_t	*mlx_img_ptr = NULL;

	data->movements++;
	movements = ft_itoa(data->movements);
	if (data->img.pc->instances[0].enabled == true)
	{
		if (!mlx_img_ptr)
			mlx_put_string(data->mlx, "Steps:", 5, 40);
		else
			mlx_delete_image(data->mlx, mlx_img_ptr);
		mlx_img_ptr = mlx_put_string(data->mlx, movements, 70, 40);
		ft_putstr_fd(C_1UP_DEL, 1);
		ft_putendl_fd(movements, 1);
	}
	free (movements);
}
