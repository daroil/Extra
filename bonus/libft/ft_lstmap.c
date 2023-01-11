/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 12:37:39 by dhendzel          #+#    #+#             */
/*   Updated: 2022/10/23 19:48:27 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*second;
	t_list	*new_start;
	t_list	*tmp_node;

	if (!f || !del || lst == NULL)
		return (NULL);
	second = ft_lstnew(f(lst->content));
	if (second == NULL)
		return (NULL);
	new_start = second;
	lst = lst->next;
	while (lst)
	{
		tmp_node = ft_lstnew(NULL);
		if (!tmp_node)
		{
			ft_lstclear(&second, del);
			return (NULL);
		}
		tmp_node->content = f(lst->content);
		ft_lstadd_back(&second, tmp_node);
		lst = lst->next;
	}
	return (new_start);
}
