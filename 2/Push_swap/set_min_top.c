/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_min_top.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 20:36:53 by spark2            #+#    #+#             */
/*   Updated: 2023/08/23 22:43:17 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 최솟값을 최상단으로! */
void	set_min_top(t_stack *stack)
{
	int		idx;

	idx = find_first_value(stack);
	if (idx > stack->a_size / 2)
	{
		while (stack->a_size - idx)
		{
			rra(stack);
			idx++;
		}
	}
	else
	{
		while (idx)
		{
			ra(stack);
			idx--;
		}
	}
}

int	find_first_value(t_stack *stack)
{
	int		idx;
	t_list	*tmp;

	idx = 0;
	tmp = stack->a_head;
	while (tmp->idx != 0)
	{
		if (tmp->idx == 0)
			break ;
		idx++;
		tmp = tmp->next;
	}
	return (idx);
}
