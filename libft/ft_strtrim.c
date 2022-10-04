/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 17:17:47 by emlicame      #+#    #+#                 */
/*   Updated: 2021/12/13 17:18:16 by emlicame      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
#1. The string to be trimmed.
#2. The reference set of characters to trim.
Return value The trimmed string. NULL if the allocation fails.
Description Allocates (with malloc(3)) and returns a copy of
’s1’ with the characters specified in ’set’ removed
from the beginning and the end of the string.
*/
#include "libft.h"

int	ft_check_in_set(char c, char const *set);
/*
int main(void)
{
	char *s1;
    char *set;

    s1 = "acbbrutteaacb";
    set = "abc";
    
    printf("%s", ft_strtrim(s1, set));
    return (0);
}
*/

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	size_t	left;
	size_t	right;
	char	*trimmed;

	left = 0;
	while ((s1[left]) && (ft_check_in_set(s1[left], set)))
		left++;
	right = ft_strlen(s1);
	while (right > left && (ft_check_in_set(s1[right - 1], set)))
		right--;
	trimmed = (char *)malloc (sizeof (*s1) * (right - left + 1));
	if (!trimmed)
		return (NULL);
	i = 0;
	while (left < right)
	{
		trimmed[i] = s1[left];
		left++;
		i++;
	}
	trimmed[i] = '\0';
	return (trimmed);
}

int	ft_check_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}
