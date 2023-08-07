/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 20:52:50 by spark2            #+#    #+#             */
/*   Updated: 2023/08/07 13:57:48 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stack)
{
	t_list	*tmp;

	if (!stack->b_head)
		return ;
	tmp = stack->b_head;
	stack->b_head = stack->b_head->next;
	tmp->next = stack->a_head;
	stack->a_head = tmp;
	printf("pa\n");
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
	printf("pb\n");
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
	printf("sa\n");
}

void	sb(t_stack *stack)
{
	t_list	*tmp;

	if (!stack->b_head || !stack->b_head->next)
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
	sa(stack);
	sb(stack);
}
