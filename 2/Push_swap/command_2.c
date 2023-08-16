/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 16:29:50 by spark2            #+#    #+#             */
/*   Updated: 2023/08/16 22:23:56 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack)
{
	t_list	*tmp;

	if (!stack->a_head || !stack->a_head->next)
		return ;
	tmp = stack->a_head->next;
	stack->a_bottom->next = stack->a_head;
	stack->a_bottom = stack->a_bottom->next;
	stack->a_head->next = 0;
	stack->a_head = tmp;
	write(1, "ra\n", 3);
}

void	rb(t_stack *stack)
{
	t_list	*tmp;

	if (!stack->b_head || !stack->b_head->next)
		return ;
	tmp = stack->b_head->next;
	stack->b_bottom->next = stack->b_head;
	stack->b_bottom = stack->b_bottom->next;
	stack->b_head->next = 0;
	stack->b_head = tmp;
	write(1, "rb\n", 3);
}

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
	write(1, "rra\n", 4);
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
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack)
{
	rra(stack);
	rrb(stack);
}
