/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tolower.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 17:18:51 by emlicame      #+#    #+#                 */
/*   Updated: 2021/12/13 17:18:52 by emlicame      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
int main(void)
{
    int letter_l;
    
    letter_l = 'e';
    printf ("ft_tolower %c\t", ft_tolower(letter_l));
    printf ("tolower %c\n", tolower(letter_l));
    return (0);
}
*/

int	ft_tolower(int c)
{
	int	lower;

	if (c >= 'A' && c <= 'Z')
	{
		lower = c + 32;
		return (lower);
	}
	else
		return (c);
}
