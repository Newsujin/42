/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:15:01 by spark2            #+#    #+#             */
/*   Updated: 2023/08/04 18:08:50 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (0);
	// if (i == 0)
	// 	node->prev = 0;
	// else
	// {
	// 	while (head->next)
	// 		head = head->next;
	// 	// node->prev = head;
	// }
	node->content = content;
	node->next = 0;
	return (node);
}

t_stack	*ft_stknew(t_list *a_head, t_list *a_bottom)
{
	t_stack	*node;
	t_list	*b_node;
	t_list	*b_node_2;
	t_list	*b_node_3;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (0);
	node->a_head = a_head;
	node->a_bottom = a_bottom;

	//test 끝나면 b_node 지우고 b 스택에 0 넣기
	b_node = malloc(sizeof(t_list));
	b_node_2 = malloc(sizeof(t_list));
	b_node_3 = malloc(sizeof(t_list));

	// b_node->prev = 0;
	b_node->content = 10;
	b_node->next = b_node_2;

	// b_node_2->prev = b_node;
	b_node_2->content = 20;
	b_node_2->next = b_node_3;

	// b_node_3->prev = b_node_2;
	b_node_3->content = 30;
	b_node_3->next = 0;

	// node->b_head = 0;
	// node->b_bottom = 0;

	node->b_head = b_node;
	node->b_bottom = b_node_3;
	return (node);
}