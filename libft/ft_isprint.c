/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isprint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 17:09:43 by emlicame      #+#    #+#                 */
/*   Updated: 2021/12/13 17:09:44 by emlicame      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
int main(void)
{
	unsigned char print;
		
	print = '\n';
	printf ("%d", ft_isprint(print));
	printf ("%d", isprint(print));
	return (0);
}
*/

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}
