/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 17:12:48 by emlicame      #+#    #+#                 */
/*   Updated: 2021/12/13 17:12:49 by emlicame      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}t_list;

Parameters #1. The beginning of the list.
Counts the number of elements in a list.
Return value Length of the list.
*/
int	ft_lstsize(t_list *lst)
{
	t_list	*current;
	int		elements;

	elements = 0;
	if (lst)
		current = lst;
	else
		return (0);
	while (current != NULL)
	{
		elements++;
		current = current->next;
	}
	return (elements);
}
