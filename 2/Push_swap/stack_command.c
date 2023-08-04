/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 20:52:50 by spark2            #+#    #+#             */
/*   Updated: 2023/07/23 18:04:02 by spark2           ###   ########.fr       */
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
	//아래 줄 lstnew 로 바꿔 간략화하기
	tmp = stack->b_head;
	// tmp = malloc(sizeof(t_list));
	// tmp->content = stack->b_head->content;
	tmp->next = stack->a_head;
	stack->a_head = tmp;
	stack->b_head = stack->b_head->next;
	// stack->b_head->prev = 0;
	// free(stack->b_head->prev);
	printf("pa\n");
}

void	push_b(t_stack *stack)
{
	t_list	*tmp;

	 if (is_empty(stack->a_head))
		return ;
	//아래 줄 lstnew 로 바꿔 간략화하기
	tmp = malloc(sizeof(t_list));
	tmp->content = stack->a_head->content;
	tmp->next = stack->b_head;
	stack->b_head = tmp;
	stack->a_head = stack->a_head->next;
	// stack->a_head->prev = 0;
	free(stack->a_head->prev);
	printf("pb\n");
}

void	swap_a(t_stack *stack)
{
	t_list	*tmp;

	if (is_empty(stack->a_head) || is_empty(stack->a_head->next))
		return ;
	tmp = stack->a_head;
	stack->a_head = stack->a_head->next;
	stack->a_head->prev = 0;
	tmp->prev = stack->a_head;
	tmp->next = stack->a_head->next;
	stack->a_head->next = tmp;
	printf("sa\n");
}

void	swap_b(t_stack *stack)
{
	t_list	*tmp;

	if (is_empty(stack->b_head) || is_empty(stack->b_head->next))
		return ;
	tmp = stack->b_head;
	stack->b_head = stack->b_head->next;
	stack->b_head->prev = 0;
	tmp->prev = stack->b_head;
	tmp->next = stack->b_head->next;
	stack->b_head->next = tmp;
	printf("sb\n");
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