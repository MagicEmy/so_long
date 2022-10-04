/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 17:07:47 by emlicame      #+#    #+#                 */
/*   Updated: 2021/12/13 17:08:18 by emlicame      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
int	main(void)
{
	char	*src;

	src = "The Empire strikes back";
	printf("%s\n", src);
	src = ft_calloc((ft_strlen(src) + 1), sizeof(char));
	printf("%d", src[0]);
	system ("leaks a.out");
	return (0);
}
*/

void	*ft_calloc(size_t count, size_t size)
{
	char	*dest;
	size_t	tot_size;
	size_t	i;

	i = 0;
	tot_size = size * count;
	dest = malloc (tot_size);
	if (dest == NULL)
		return (NULL);
	while (i < tot_size)
	{
		dest[i] = 0;
		i++;
	}
	return (dest);
}
