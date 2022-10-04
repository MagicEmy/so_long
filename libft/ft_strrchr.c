/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 17:17:38 by emlicame      #+#    #+#                 */
/*   Updated: 2021/12/13 17:17:39 by emlicame      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*

int	 main(void)
{
    int c;
    const char *s_revchr;

    c = 'u';
    s_revchr = "Bibuba";
    printf("%s\n", ft_strrchr(s_revchr, c));
    printf("%s", strrchr(s_revchr, c));
    return (0);
}
*/

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	*temp;

	temp = NULL;
	len = ft_strlen(s);
	if (c == '\0')
		return ((char *)s + len);
	while (*s != '\0')
	{
		if ((unsigned char)(*s) == (unsigned char) c)
		{
			temp = (char *) s;
		}
		s++;
	}
	return (temp);
}
