/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 19:20:35 by spark2            #+#    #+#             */
/*   Updated: 2023/08/16 20:50:15 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

// t_stack	*ft_stknew(t_list *a_head, t_list *a_bottom)
// {
// 	t_stack	*node;

// 	node = malloc(sizeof(t_stack));
// 	if (!node)
// 		return (0);
// 	node->a_head = a_head;
// 	node->a_bottom = a_bottom;
// 	node->b_head = 0;
// 	node->b_bottom = 0;
// 	return (node);
// }

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
	while (lst->next) //lst == 0은 lst 자체가 없는 걸 의미, 따라서 lst->next == 0 조건문으로 판별
	{
		if (lst->content == new->content) //리스트에 content 중복이 있는지 체크
			return (0);
		lst = lst->next;
	}
	if (lst->content == new->content)
		return (0);
	return (lst);
}
