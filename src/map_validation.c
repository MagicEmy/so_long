/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_validation.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: emanuela <emanuela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 17:19:28 by emanuela      #+#    #+#                 */
/*   Updated: 2022/10/03 17:45:08 by emanuela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_exit(char *text)
{
	printf("Error\n");
	printf("%s\n", text);
	exit (1);
}

/*
if (argc != 2)
		error_exit("Arguments are not valid");
*/
void    check_extension(char *argv)
{
    int len;

    len = ft_strlen(argv) - 4;
    if (ft_strncmp(argv[len], ".ber", 4) != 0)
        error_exit("Wrong map extension");
}

void    map_validation(char *argv)
{
    
}