/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 17:16:50 by emlicame          #+#    #+#             */
/*   Updated: 2022/10/09 19:13:09 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_info
{
	int				width;
	int				height;
	mlx_t			*mlx;
	mlx_image_t		*tile;
}	t_info;

void    map_validation(char *argv);
void    check_extension(char *argv);
void	error_exit(char *text);

//get_next_line
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strjoin_free(char *s1, char *s2);
int		check_where_newline(char *buff, int c);

#endif // SO_LONG_H