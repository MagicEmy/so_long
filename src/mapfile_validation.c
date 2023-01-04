/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mapfile_validation.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 11:46:26 by emlicame      #+#    #+#                 */
/*   Updated: 2022/12/26 13:16:16 by emanuela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'P' || c == 'C' || c == 'E' || \
	c == '\n');
}

void	check_map_syntax(char *mapline, t_data *data)
{
	int		i;

	i = 0;
	while (mapline[i])
	{
		if (!ft_valid_char(mapline[i]))
			error_exit("Invalid char in map.");
		if (mapline[i] == 'C')
			data->c++;
		else if (mapline[i] == 'P')
			data->p++;
		else if (mapline[i] == 'E')
			data->e++;
		i++;
	}
	if (data->c < 1)
		error_exit("Amount of collectibles is 0.");
	if (data->p != 1)
		error_exit("Amount of Player starting position is not 1.");
	if (data->e != 1)
		error_exit("Amount of Exit point is not 1.");
}

char	*get_line(char *argv)
{
	char	*line;
	char	*map_line;
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		error_exit("File opening failed.");
	line = ft_strdup("");
	if (!line)
		error_exit("Memory allocation failed.");
	map_line = ft_strdup("");
	if (!map_line)
		error_exit("Memory allocation failed.");
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL || line[0] == '\n')
			break ;
		map_line = ft_strjoin_free(map_line, line);
		free(line);
	}
	close(fd);
	return (map_line);
}

void	check_extension(char *argv)
{
	int	len;

	len = ft_strlen(argv) - 4;
	if (ft_strncmp(&argv[len], ".ber", 4) != 0)
		error_exit("Wrong map extension.");
}

void	mapfile_validation(char *argv, t_data *data)
{
	char	*map_line;

	(void)data;
	check_extension(argv);
	map_line = get_line(argv);
	if (ft_strncmp(map_line, "", 1) == 0)
		error_exit("Empty file.");
	check_map_syntax(map_line, data);
	// map_parsing(map_line, data);
	//check if rectangle
	//check if borders are walls
}

/*
if (consecutive_newline(input))
		exit_with_message("Error\nConsecutive newline");
	splitted = ft_split(input, '\n');
	free(input);
	if (!splitted)
		exit_with_message("Error\nMalloc failed");
	if (!splitted[0])
		exit_with_message("Error\nFile only contains newline");
	return (splitted);
	*/