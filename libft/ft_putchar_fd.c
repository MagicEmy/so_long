/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 17:14:16 by emlicame      #+#    #+#                 */
/*   Updated: 2021/12/13 17:14:17 by emlicame      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
void	ft_putchar_fd(char c, int fd);

int	main(void)
{
	ft_putchar_fd('M', 1);
	return (0);
}
*/
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
