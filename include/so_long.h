/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 17:16:50 by emlicame          #+#    #+#             */
/*   Updated: 2023/01/05 16:39:53 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	1
# endif

# define RESIZE_TRUE	1
# define RESIZE_FALSE	0
# define WINDOW_WIDTH	512
# define WINDOW_HEIGHT	512
# define TILE_SIZE		64

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <memory.h>

typedef struct s_images
{
	mlx_image_t		*wall;
	mlx_image_t		*pc;
}	t_images;

typedef struct s_data
{
	int				width;
	int				height;
	int				c;
	int				p;
	int				e;
	mlx_t			*mlx;
	t_images		img;
	char			**map;
}	t_data;

void	error_exit(char *text);
void	sl_free_mem(char ***array);
void	key_hook(mlx_key_data_t keydata, void *param);
void	sl_get_images(t_data *data);
void	sl_images_to_window(t_data *data);
void	check_if_rectangle(t_data *data);
void	check_if_frame_is_wall(t_data *data);

void	mapfile_validation(char *argv, t_data *info);
void	map_validation(char *argv);
void	map_parsing(char *map_line, t_data *data);

//get_next_line
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*gnl_ft_strjoin_free(char *s1, char *s2);
int		check_where_newline(char *buff, int c);

#endif