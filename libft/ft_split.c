/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 17:14:53 by emlicame      #+#    #+#                 */
/*   Updated: 2021/12/13 17:14:54 by emlicame      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c);
size_t	ft_sep_count(char const *s, char c);
int		ft_alloc_copy(char const *s, char c, char **split, size_t sep);
int		ft_free_mem(char **split);
/*
int	main(void)
{
	char		c;
	char const	*s;
	char		**ptr;
	int			cc;

	c = ' ';
	cc = 0;
	s = "gg   gkgkgkuhi n;jhl g;j; hkg g lkj;k go";
	ptr = ft_split(s, c);
	while (ptr[cc])
		printf("|%s|\n", ptr[cc++]);
	system ("leaks a.out");
	return (0);
}
*/

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	sep;

	if (!s)
		return (NULL);
	sep = ft_sep_count(s, c);
	split = (char **)ft_calloc((sep + 1), (sizeof(char *)));
	if (!split)
		return (NULL);
	if (ft_alloc_copy(s, c, split, sep))
		return (0);
	return (split);
}

int	ft_alloc_copy(char const *s, char c, char **split, size_t sep)
{
	size_t		len;
	size_t		index;
	size_t		i;

	i = 0;
	index = 0;
	while (index < sep)
	{
		len = 0;
		while (s[i + len] != c && s[i + len] != '\0')
		{
			len++;
			if (s[i + len] == c || s[i + len] == '\0')
			{
				split[index] = ft_substr(s, i, len);
				if (!split[index++])
					ft_free_mem(split);
			}
		}
		i += len + 1;
	}
	split[index] = 0;
	return (0);
}

size_t	ft_sep_count(char const *s, char c)
{
	int		i;
	size_t	sep;

	i = 0;
	sep = 0;
	if (s[i] != c && s[i] != '\0')
	{
		sep++;
		i++;
	}
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			sep++;
		i++;
	}
	return (sep);
}

int	ft_free_mem(char **split)
{
	int	c;

	c = 0;
	while (split[c])
	{
		free(split[c]);
		c++;
	}
	free(split);
	return (1);
}
/*
write(1, ">", 1);
write(1, &s[i], len);
write(1, "<\n", 2);
*/