/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/24 17:16:50 by emlicame      #+#    #+#                 */
/*   Updated: 2022/12/26 13:06:41 by emanuela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WIDTH 256
# define HEIGHT 256
# define TILE_SIZE 64

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <memory.h>

typedef struct s_data
{
	int				width;
	int				height;
	int				c;
	int				p;
	int				e;
	mlx_t			*mlx;
	mlx_image_t		*tile;
	char			**map;
}	t_data;

void	map_validation(char *argv);
void	error_exit(char *text);
void	ft_free_mem(char ***array);
void	key_hook(mlx_key_data_t keydata, void *param);

//get_next_line
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strjoin_free(char *s1, char *s2);
int		check_where_newline(char *buff, int c);

void	mapfile_validation(char *argv, t_data *info);
void	init_context(t_data *data);
void	map_parsing(char *map_line, t_data *data);
#endif // SO_LONG_H