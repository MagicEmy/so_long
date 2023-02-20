/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 16:14:41 by emlicame          #+#    #+#             */
/*   Updated: 2023/01/12 17:43:34 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <string.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
	{
		len++;
	}
	return (len);
}

char	*gnl_ft_strjoin_free(char *s1, char *s2)
{
	size_t	x;
	size_t	total_len;
	size_t	i;
	char	*new_string;

	i = 0;
	x = 0;
	if (!s1 && !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	new_string = (char *)malloc(sizeof(char) * total_len);
	if (!new_string)
		return (new_string);
	while (s1[x])
		new_string[i++] = s1[x++];
	while (*s2)
		new_string[i++] = *s2++;
	free(s1);
	new_string[i] = '\0';
	return (new_string);
}

int	check_where_newline(char *buff, int c)
{
	int	i;

	i = 0;
	while (buff[i] != c)
	{
		if (buff[i] == '\0')
			return (-1);
		i++;
	}
	return (i);
}

char	*get_line(char *argv)
{
	char	*line;
	char	*map_line;
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		error_exit("File opening failed.");
	map_line = ft_strdup("");
	if (!map_line)
		error_exit(ERROR_MALLOC);
	line = NULL;
	while (1)
	{
		free(line);
		line = get_next_line(fd);
		if (line == NULL || line[0] == '\n')
			break ;
		map_line = gnl_ft_strjoin_free(map_line, line);
	}
	free(line);
	close(fd);
	return (map_line);
}
