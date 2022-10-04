/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 17:15:08 by emlicame      #+#    #+#                 */
/*   Updated: 2021/12/13 18:50:59 by emlicame      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*

int	main(void)
{
	int			c;
	const char	*s;

	c = 'u';
	s = "Bibuba";
	printf("|%s|\n", ft_strchr(s, 't' + 256));
	printf("%s", strchr(s, 't' + 256));
	system ("leaks a.out");
	return (0);
}
*/
char	*ft_strchr(const char *s, int c)
{
	char	*string;

	string = (char *)s;
	while (*string != c)
	{
		if (*string == '\0')
			return (NULL);
		string++;
	}
	return (string);
}
