/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******** <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 12:35:20 by ********          #+#    #+#             */
/*   Updated: 2026/10/23 15:59:17 by ********         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstmap_helper(void *content, void (*del)(void *))
{
	if (!content)
		return (NULL);
	del(content);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*result;
	void	*content;

	if (!lst)
		return (NULL);
	content = f(lst->content);
	result = ft_lstnew(content);
	if (!result)
		return (ft_lstmap_helper(content, del));
	head = result;
	while (lst->next != NULL)
	{
		lst = lst->next;
		content = f(lst->content);
		result->next = ft_lstnew(content);
		if (!result->next)
		{
			del(content);
			ft_lstclear(&head, del);
			return (NULL);
		}
		result = result->next;
	}
	return (head);
}
