/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 17:16:13 by emlicame      #+#    #+#                 */
/*   Updated: 2021/12/13 17:16:14 by emlicame      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	size_t	d_len;
	size_t	s_len;

	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	if (dsize < d_len)
		return (dsize + s_len);
	else
	{
		dst = dst + d_len;
		ft_strlcpy(dst, src, dsize - d_len);
		return (d_len + s_len);
	}
}
/*
int  main(void)
{
    char src[] = "THIS IS THE SOURCE";
    char dst[50] = "this is the destination";
    // ft_strlcat(dst, src, 19);
    printf("%zu\n", ft_strlcat(dst, src, sizeof(dst)));
    printf("%s\n", dst);
    return (0);
}
*/