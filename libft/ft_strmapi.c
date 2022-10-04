/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 17:17:01 by emlicame      #+#    #+#                 */
/*   Updated: 2021/12/13 17:17:02 by emlicame      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
int	main(void)
{
	char	*s;

	s = "iteration";
	ft_strmapi(s, (*f)(unsigned int, char));
	return (0);
}
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new_string;
	size_t			len;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	new_string = (char *) malloc(sizeof(char) * len + 1);
	if (!new_string)
		return (NULL);
	while (s[i])
	{
		new_string[i] = f(i, s[i]);
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}
