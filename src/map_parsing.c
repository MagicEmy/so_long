/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 18:15:53 by emlicame          #+#    #+#             */
/*   Updated: 2022/10/09 19:13:35 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char    *get_line(argv)
{
    char    *line;
    char    *map_line;
    int     fd;
    
    fd = open(argv, O_RDONLY);
    if (fd < 0)
        error_exit("File opening failed.");
    line = "";
    map_line = ft_strdup("");
    if (!map_line)
        error_exit("memory allocation failed.");
    while (line)
    {
        line = get_next_line(fd);
        if (line == NULL || line[0] == '\n')
			break ;
        map_line = *ft_strjoin_free(char *s1, char *s2)(map_line, line);
		free(line);
    }
    free(line);
    close(fd);
    if (map_line == 0)
        error_exit("map is empty.");
    return (map_line);
}

void    map_parsing(char *argv, t_info *info)
{
    char    *map_line;

    map_line = get_line(argv);
}


//(ft_split(all_lines, '\n'));
