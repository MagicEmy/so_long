/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isdigit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 17:09:33 by emlicame      #+#    #+#                 */
/*   Updated: 2021/12/13 17:09:35 by emlicame      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
int main(void)
{
	char digit;
    
    digit = '5';
    printf ("%d", ft_isdigit(digit));
    printf ("%d", isdigit(digit));
    return (0);
}
*/

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
