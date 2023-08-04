/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 20:52:50 by spark2            #+#    #+#             */
/*   Updated: 2023/08/04 22:32:08 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_empty(t_list *node)
{
	return (node == 0);
}

void	push_a(t_stack *stack)
{
	t_list	*tmp;

	if (is_empty(stack->b_head))
		return ;
	tmp = stack->b_head;
	stack->b_head = stack->b_head->next;
	tmp->next = stack->a_head;
	stack->a_head = tmp;
	printf("pa\n");
}

void	push_b(t_stack *stack)
{
	t_list	*tmp;

	if (is_empty(stack->a_head))
		return ;
	tmp = stack->a_head;
	stack->a_head = stack->a_head->next;
	tmp->next = stack->b_head;
	stack->b_head = tmp;
	printf("pb\n");
}

void	swap_a(t_stack *stack)
{
	t_list	*tmp;

	if (is_empty(stack->a_head) || is_empty(stack->a_head->next))
		return ;
	tmp = stack->a_head;
	stack->a_head = stack->a_head->next;
	tmp->next = stack->a_head->next;
	stack->a_head->next = tmp;
	printf("sa\n");
}

void	swap_b(t_stack *stack)
{
	t_list	*tmp;

	if (is_empty(stack->b_head) || is_empty(stack->b_head->next))
		return ;
	//했는데 기억 안 남 아래 과정
	tmp = stack->b_head;
	stack->b_head = stack->b_head->next;
	tmp->next = stack->b_head->next;
	stack->b_head->next = tmp;
	printf("sb\n");
}

void	ss(t_stack *stack)
{
	swap_a(stack);
	swap_b(stack);
}
void	rotate_a(t_stack *stack)
{
	t_list	*tmp;

	if (is_empty(stack->a_head) || is_empty(stack->a_head->next))
		return ;
	tmp = stack->a_head->next;
	stack->a_bottom->next = stack->a_head;
	stack->a_bottom = stack->a_bottom->next;
	stack->a_head->next = 0;
	stack->a_head = tmp;
}

void	rotate_b(t_stack *stack)
{
	t_list	*tmp;
	if (is_empty(stack->b_head) || is_empty(stack->b_head->next))
		return ;
	tmp = stack->b_head->next;
	stack->b_bottom->next = stack->b_head;
	stack->b_bottom = stack->b_bottom->next;
	stack->b_head->next = 0;
	stack->b_head = tmp;
}

void	rra(t_stack *stack)
{
	t_list	*last;
	t_list	*prev_last;


	if (is_empty(stack->a_head) || is_empty(stack->a_head->next))
		return ;
	last = stack->a_head;
	while (last->next)
	{
		prev_last = last;
		last = prev_last->next;
	}
	prev_last->next = 0;
	last->next = stack->a_head;
	stack->a_head = last;
}

void	rrb(t_stack *stack)
{
	t_list	*last;
	t_list	*prev_last;


	if (is_empty(stack->b_head) || is_empty(stack->b_head->next))
		return ;
	last = stack->b_head;
	while (last->next)
	{
		prev_last = last;
		last = prev_last->next;
	}
	prev_last->next = 0;
	last->next = stack->b_head;
	stack->b_head = last;
}

void	rrr(t_stack *stack)
{
	rra(stack);
	rrb(stack);
}