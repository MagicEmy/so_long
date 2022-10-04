/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdelone.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 17:11:31 by emlicame      #+#    #+#                 */
/*   Updated: 2021/12/13 17:11:33 by emlicame      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
Parameters 
#1. The element to free.
#2. The address of the function used to delete the content.
Takes as a parameter an element and frees the memory of the element’s 
content using the function ’del’ given as a parameter and free the element.
The memory of ’next’ must not be freed.

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}t_list;
*/
#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst && !del)
		return ;
	del(lst->content);
	free (lst);
}
