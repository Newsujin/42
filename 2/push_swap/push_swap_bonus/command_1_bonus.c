/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_1_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 20:52:50 by spark2            #+#    #+#             */
/*   Updated: 2023/08/25 19:54:00 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	pa(t_stack *stack)
{
	t_list	*tmp;

	if (!stack->b_head)
		return ;
	tmp = stack->b_head;
	stack->b_head = stack->b_head->next;
	tmp->next = stack->a_head;
	stack->a_head = tmp;
}

void	pb(t_stack *stack)
{
	t_list	*tmp;

	if (!stack->a_head)
		return ;
	if (stack->b_head && !stack->b_bottom)
		stack->b_bottom = stack->b_head;
	tmp = stack->a_head;
	stack->a_head = stack->a_head->next;
	tmp->next = stack->b_head;
	stack->b_head = tmp;
}

void	sa(t_stack *stack)
{
	t_list	*tmp;

	if (!stack->a_head || !stack->a_head->next)
		return ;
	tmp = stack->a_head;
	stack->a_head = stack->a_head->next;
	tmp->next = stack->a_head->next;
	stack->a_head->next = tmp;
}

void	sb(t_stack *stack)
{
	t_list	*tmp;

	if (!stack->b_head || !stack->b_head->next)
		return ;
	tmp = stack->b_head;
	stack->b_head = stack->b_head->next;
	tmp->next = stack->b_head->next;
	stack->b_head->next = tmp;
}

void	ss(t_stack *stack)
{
	sa(stack);
	sb(stack);
}
