/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalpha.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 17:08:58 by emlicame      #+#    #+#                 */
/*   Updated: 2021/12/13 17:09:10 by emlicame      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
int main(void)
{
    int alpha;
    
    alpha = 'e';
    printf ("%d", ft_isalpha(alpha));
    printf ("%d", isalpha(alpha));
    return (0);
}
*/

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}	
