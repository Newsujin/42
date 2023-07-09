/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 20:52:50 by spark2            #+#    #+#             */
/*   Updated: 2023/07/09 21:59:20 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_empty(t_stack *stack)
{
	return (stack->a_head == 0);
}
void	push_front(t_stack *stack, int item)
{
	t_list	*tmp;

	//아래 줄 lstnew 로 바꿔 간략화하기
	tmp = malloc(sizeof(t_list));
	tmp->content = item;
	tmp->next = stack->a_head;
	stack->a_head = tmp;
}