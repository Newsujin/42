/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_func_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 19:20:35 by spark2            #+#    #+#             */
/*   Updated: 2023/08/24 22:22:50 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_list	*ft_lstnew(int content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (0);
	node->content = content;
	node->next = 0;
	node->idx = 0;
	return (node);
}

int	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!*lst)
		*lst = new;
	else
	{
		tmp = ft_lstlast(*lst, new);
		if (!tmp)
			return (0);
		tmp->next = new;
	}
	return (1);
}

t_list	*ft_lstlast(t_list *lst, t_list *new)
{
	while (lst->next)
	{
		if (lst->content == new->content)
		{
			write(1, "Error\n", 6);
			return (0);
		}
		lst = lst->next;
	}
	if (lst->content == new->content)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (lst);
}
