/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 17:14:03 by emlicame      #+#    #+#                 */
/*   Updated: 2021/12/13 17:14:09 by emlicame      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* DESCRIPTION The memset() function writes len bytes 
of value c (converted to an unsigned char) to the string b. */
/* RETURN VALUES The memset() function returns its first argument. */

/*
int	main(void)
{
	char	b[20] = "Codam";
	int		c;
	size_t	len;

	c = 'A';
	len = 2;
	ft_memset(b, c, len);
	printf ("%s", b);
	system ("leaks a.out");
	return (0);
}
*/

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*new;

	new = (unsigned char *)b;
	while (len-- > 0)
	{
		*new++ = (unsigned char)c;
	}
	return (b);
}
