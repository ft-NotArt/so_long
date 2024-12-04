/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 08:51:26 by anoteris          #+#    #+#             */
/*   Updated: 2024/10/20 06:58:12 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*current_lst ;
	t_list	*new_node ;
	t_list	*first_new ;
	void	*tmp ;

	if (!lst || !f || !del)
		return (NULL);
	current_lst = lst;
	first_new = NULL;
	while (current_lst)
	{
		tmp = f(current_lst->content);
		new_node = ft_lstnew(tmp);
		if (!new_node)
		{
			del(tmp);
			ft_lstclear(&first_new, del);
			return (NULL);
		}
		ft_lstadd_back(&first_new, new_node);
		current_lst = current_lst->next;
	}
	return (first_new);
}
