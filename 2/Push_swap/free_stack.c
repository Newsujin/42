/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:12:08 by spark2            #+#    #+#             */
/*   Updated: 2023/08/22 20:21:42 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_list	*tmp;
	t_list	*node;

	node = stack->a_head;
	while (node)
	{
		tmp = node->next;
		free(node);
		node = 0;
		node = tmp;
	}
	node = stack->b_head;
	while (node)
	{
		tmp = node->next;
		free(node);
		node = 0;
		node = tmp;
	}
	exit(1);
}
