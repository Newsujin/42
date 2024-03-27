/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_3_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 21:42:42 by spark2            #+#    #+#             */
/*   Updated: 2023/08/25 19:54:16 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rra(t_stack *stack)
{
	t_list	*last;
	t_list	*prev_last;

	if (!stack->a_head || !stack->a_head->next)
		return ;
	last = stack->a_head;
	while (last->next)
	{
		prev_last = last;
		last = prev_last->next;
	}
	prev_last->next = 0;
	stack->a_bottom = prev_last;
	last->next = stack->a_head;
	stack->a_head = last;
}

void	rrb(t_stack *stack)
{
	t_list	*last;
	t_list	*prev_last;

	if (!stack->b_head || !stack->b_head->next)
		return ;
	last = stack->b_head;
	while (last->next)
	{
		prev_last = last;
		last = prev_last->next;
	}
	prev_last->next = 0;
	stack->b_bottom = prev_last;
	last->next = stack->b_head;
	stack->b_head = last;
}

void	rrr(t_stack *stack)
{
	rra(stack);
	rrb(stack);
}
