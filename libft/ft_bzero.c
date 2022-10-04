/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 15:01:37 by emlicame      #+#    #+#                 */
/*   Updated: 2021/12/13 15:01:47 by emlicame      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*

int main(void)
{
    char s[20] = "Codam";
    char w[20] = "Codam";
    size_t n;
    
    n = 2;
    ft_bzero(s, n);
    printf("%s \n", s);
    bzero(w, n);
    printf("%s \n", w);   
    return (0);
}
*/
void	ft_bzero(void *s, size_t n)
{
	if (n > 0)
	{
		while (n-- > 0)
		{
			*(unsigned char *)s++ = 0;
		}
	}
}
