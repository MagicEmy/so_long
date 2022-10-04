/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 17:11:15 by emlicame      #+#    #+#                 */
/*   Updated: 2021/12/13 17:11:16 by emlicame      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*Parameters 
#1. The address of a pointer to an element.
#2. The address of the function used to delete the content of the element.
Deletes and frees the given element and every successor of that element, 
using the function ’del’ and free(3).
Finally, the pointer to the list must be set to NULL.
*/
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst && !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		del((*lst)->content);
		free (*lst);
		*lst = temp;
	}
}
//ft_lstdelone(*lst, del);