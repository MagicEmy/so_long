/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isascii.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 17:09:24 by emlicame      #+#    #+#                 */
/*   Updated: 2021/12/13 17:09:26 by emlicame      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
int main(void)
{
    unsigned char ascii;
    
    ascii = 220;
    printf ("%d", ft_isascii(ascii));
    printf ("%d", isascii(ascii));
    return (0);
}
*/

int	ft_isascii(int h)
{
	if (h >= 0 && h <= 127)
		return (1);
	else
		return (0);
}
