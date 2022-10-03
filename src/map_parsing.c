/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_parsing.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: emanuela <emanuela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 17:36:19 by emanuela      #+#    #+#                 */
/*   Updated: 2022/10/03 17:54:01 by emanuela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    parse_map(char *argv, t_info *info)
{
    int     fd;
    char    *map_vector;

    fd = open(argv, O_RDONLY)
    if (fd < 0)
        error_exit("Open failed");
    /*
    map_vector = gnl(argv);
     
    */
   close (fd);
}