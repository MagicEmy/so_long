/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 17:58:35 by emlicame          #+#    #+#             */
/*   Updated: 2023/01/05 12:06:18 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	new_line_index(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	return (i);
}

char	*check_data_in_buffer(char *line, char *static_buff)
{
	int		i;
	int		j;
	int		p;
	char	*s;

	j = 0;
	i = new_line_index(line);
	s = malloc(i + 1);
	if (!s)
		return (NULL);
	p = 0;
	while (line[p])
	{
		if (p >= i)
			*static_buff++ = line[p++];
		else
			s[j++] = line[p++];
	}
	s[i] = '\0';
	*static_buff = '\0';
	free(line);
	return (s);
}

char	*free_mem(char **s1, char **s2)
{
	free(*s1);
	free(*s2);
	return (NULL);
}

char	*read_bytes(int fd, char *read_buff)
{
	int			x;
	ssize_t		res;
	char		*ret_line;

	res = 1;
	ret_line = (char *)malloc(1 * sizeof(char));
	if (!ret_line)
		return (NULL);
	ret_line[0] = '\0';
	ret_line = gnl_ft_strjoin_free(ret_line, read_buff);
	x = check_where_newline(ret_line, '\n');
	while (res && x == -1)
	{
		res = read(fd, read_buff, BUFFER_SIZE);
		if (res >= 0)
		{
			read_buff[res] = '\0';
			ret_line = gnl_ft_strjoin_free(ret_line, read_buff);
			x = check_where_newline(read_buff, '\n');
		}
		if (res <= 0 && !ret_line[0])
			return (free_mem(&read_buff, &ret_line));
	}
	return (ret_line);
}

char	*get_next_line(int fd)
{
	static char	*static_buff;
	char		*line;

	if (read(fd, NULL, 0) == -1 || BUFFER_SIZE < 1)
		return (NULL);
	if (!static_buff)
	{
		static_buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!static_buff)
			return (NULL);
		static_buff[0] = '\0';
	}
	line = read_bytes(fd, static_buff);
	if (!line)
	{
		static_buff = NULL;
		return (NULL);
	}
	line = check_data_in_buffer(line, static_buff);
	if (!line)
		return (NULL);
	return (line);
}
