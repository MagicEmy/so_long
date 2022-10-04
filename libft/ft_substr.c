/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 17:18:35 by emlicame      #+#    #+#                 */
/*   Updated: 2021/12/13 17:18:36 by emlicame      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
#1. The string from which to create the substring. 
#2. The start index of the substring in the string ’s’.
#3. The maximum length of the substring.

Return value The substring. NULL if the allocation fails.

Allocates (with malloc(3)) and returns a substring from the string ’s’.
The substring begins at index ’start’ and is of maximum size ’len’.
*/
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*string;
	unsigned int	i;
	size_t			j;

	i = start;
	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	string = (char *)malloc(len + 1);
	if (string == NULL)
		return (string);
	j = 0;
	while (s[i] && j < len)
	{
		string[j] = s[i];
		i++;
		j++;
	}
	string[j] = '\0';
	return (string);
}
