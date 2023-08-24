/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_indexing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 21:47:19 by spark2            #+#    #+#             */
/*   Updated: 2023/08/24 21:33:14 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	numbering(t_stack stack, t_list *new)
{
	t_list	*cur;

	cur = stack.a_head;
	while (cur != new)
	{
		if (cur->content > new->content)
			cur->idx++;
		else
			new->idx++;
		cur = cur->next;
	}
}

void	pick_pivot(t_stack *stack)
{
	t_list	*tmp;

	tmp = stack->a_head;
	while (tmp)
	{
		if (tmp->idx == stack->a_size / 3)
			stack->pivot1 = tmp->content;
		else if (tmp->idx == (stack->a_size) * 2 / 3)
			stack->pivot2 = tmp->content;
		tmp = tmp->next;
	}
}
