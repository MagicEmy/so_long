/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 17:16:51 by emlicame      #+#    #+#                 */
/*   Updated: 2021/12/13 17:16:52 by emlicame      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*

int main(void)
{
    const char *str;
    
    str = "Galaxy";
    printf ("%lu", ft_strlen(str));
    printf ("%lu", strlen(str));
    return (0);
}
*/

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}
