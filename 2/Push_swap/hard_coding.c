/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_coding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 22:01:19 by spark2            #+#    #+#             */
/*   Updated: 2023/08/23 22:51:53 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	hard_coding(t_stack *stack)
{
	while (stack->a_size > 5)
	{
		pb(stack);
		stack->a_size--;
		stack->b_size++;
	}
	if (stack->a_size == 1)
		return ;
	else if (stack->a_size == 2)
		return (sort_2_contents(stack));
	else if (stack->a_size == 3)
		return (sort_3_contents(stack));
	else if (stack->a_size == 4)
		return (sort_4_contents(stack));
	else
		return (sort_5_contents(stack));
}

void	move_2_element(t_stack *stack)
{
	int		idx;
	int		cnt;
	t_list	*tmp;

	cnt = 0;
	idx = find_min(stack);
	while (cnt < 2)
	{
		tmp = stack->a_head;
		if (tmp->content != stack->min)
		{
			if (idx > stack->a_size / 2)
				rra(stack);
			else
				ra(stack);
		}
		else
		{
			pb(stack);
			cnt++;
			idx = find_min(stack);
		}
	}
}

int	find_min(t_stack *stack)
{
	int		idx;
	t_list	*tmp;

	idx = -1;
	tmp = stack->a_head;
	stack->min = 2147483647;
	while (tmp)
	{
		if (tmp->content < stack->min)
		{
			stack->min = tmp->content;
			idx++;
		}
		tmp = tmp->next;
	}
	return (idx);
}
