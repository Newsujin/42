/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_min_top.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 20:36:53 by spark2            #+#    #+#             */
/*   Updated: 2023/08/28 12:41:44 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_min_top(t_stack *stack)
{
	int		idx;

	idx = find_first_value(stack);
	if (idx > stack->a_size / 2)
	{
		while (stack->a_size - idx)
		{
			rra(stack, 0);
			idx++;
		}
	}
	else
	{
		while (idx)
		{
			ra(stack, 0);
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
