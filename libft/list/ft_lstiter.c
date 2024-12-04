/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 06:39:08 by anoteris          #+#    #+#             */
/*   Updated: 2024/10/20 07:02:32 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*current;
	t_list	*next;

	if (!lst || !f)
		return ;
	current = lst;
	while (current)
	{
		next = current->next;
		f(current->content);
		current = next;
	}
}
