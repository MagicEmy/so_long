/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstiter.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 17:11:42 by emlicame      #+#    #+#                 */
/*   Updated: 2021/12/13 17:11:45 by emlicame      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Parameters 
#1. The adress of a pointer to an element.
#2. The adress of the function used to iterate on the list.
Description Iterates the list ’lst’ and applies the function
’f’ to the content of each element.
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}t_list;
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*current;

	current = NULL;
	if (lst && f)
		current = lst;
	while (current != NULL)
	{
		f(current->content);
		current = current->next;
	}
}
