/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalnum.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 17:08:45 by emlicame      #+#    #+#                 */
/*   Updated: 2021/12/13 17:08:48 by emlicame      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
int main(void)
{
    char digit;
    
    digit = 'e';
    printf ("%d", ft_isalnum(digit));
    printf ("%d", isalnum(digit));
    return (0);
}
*/
int	ft_isalnum(int c)
{
	if ((ft_isalpha(c)) || (ft_isdigit(c)))
		return (1);
	else
		return (0);
}
