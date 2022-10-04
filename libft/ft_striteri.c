/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striteri.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 17:15:37 by emlicame      #+#    #+#                 */
/*   Updated: 2021/12/13 17:15:38 by emlicame      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*

int		main(void)
{
	ft_striteri(s, f(ui, s[ui]));??
	return (0);
}
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{	
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
	s[i] = '\0';
}
