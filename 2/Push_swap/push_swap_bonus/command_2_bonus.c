/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 16:29:50 by spark2            #+#    #+#             */
/*   Updated: 2023/08/25 19:53:51 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
}

void	rr(t_stack *stack)
{
	ra(stack);
	rb(stack);
}
