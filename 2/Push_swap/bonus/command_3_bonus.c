/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_3_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 21:42:42 by spark2            #+#    #+#             */
/*   Updated: 2023/08/24 22:22:33 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rra(t_stack *stack, int rrr_flag)
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
	if (rrr_flag == 0)
		write(1, "rra\n", 4);
}

void	rrb(t_stack *stack, int rrr_flag)
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
	if (rrr_flag == 0)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack)
{
	rra(stack, 1);
	rrb(stack, 1);
	write(1, "rrr\n", 4);
}
