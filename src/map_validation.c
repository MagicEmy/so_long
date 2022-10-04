/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:46:26 by emlicame          #+#    #+#             */
/*   Updated: 2022/10/04 11:52:09 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_exit(char *text)
{
	printf("Error\n");
	printf("%s\n", text);
	exit (1);
}

void    check_extension(char *argv)
{
    int len;

    len = ft_strlen(argv) - 4;
    if (ft_strncmp(&argv[len], ".ber", 4) != 0)
        error_exit("Wrong map extension");
}

void    map_validation(char *argv)
{
    check_extension(argv);
}