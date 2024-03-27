/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 16:29:50 by spark2            #+#    #+#             */
/*   Updated: 2023/08/24 21:43:08 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack, int rr_flag)
{
	t_list	*tmp;

	if (!stack->a_head || !stack->a_head->next)
		return ;
	tmp = stack->a_head->next;
	stack->a_bottom->next = stack->a_head;
	stack->a_bottom = stack->a_bottom->next;
	stack->a_head->next = 0;
	stack->a_head = tmp;
	if (rr_flag == 0)
		write(1, "ra\n", 3);
}

void	rb(t_stack *stack, int rr_flag)
{
	t_list	*tmp;

	if (!stack->b_head || !stack->b_head->next)
		return ;
	tmp = stack->b_head->next;
	stack->b_bottom->next = stack->b_head;
	stack->b_bottom = stack->b_bottom->next;
	stack->b_head->next = 0;
	stack->b_head = tmp;
	if (rr_flag == 0)
		write(1, "rb\n", 3);
}

void	rr(t_stack *stack)
{
	ra(stack, 1);
	rb(stack, 1);
	write(1, "rr\n", 3);
}
