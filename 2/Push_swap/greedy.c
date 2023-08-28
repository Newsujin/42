/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:03:01 by spark2            #+#    #+#             */
/*   Updated: 2023/08/28 12:40:51 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	greedy(t_stack *stack)
{
	int		i;
	int		min;
	t_list	*tmp;

	while (stack->b_size)
	{
		i = -1;
		min = 2147483647;
		tmp = stack->b_head;
		while (tmp)
		{
			stack->rb_count = rb_cnt(stack, ++i);
			stack->ra_count = ra_cnt(stack, tmp->content);
			if (ft_abs(stack->rb_count) + ft_abs(stack->ra_count) < min)
			{
				min = ft_abs(stack->rb_count) + ft_abs(stack->ra_count);
				stack->ra_final = stack->ra_count;
				stack->rb_final = stack->rb_count;
			}
			tmp = tmp->next;
		}
		b_to_a(stack, stack->ra_final, stack->rb_final);
		stack->b_size--;
		stack->a_size++;
	}
}

int	rb_cnt(t_stack *stack, int idx)
{
	if ((stack->b_size / 2) < idx)
		return (-(stack->b_size - idx));
	return (idx);
}

int	ra_cnt(t_stack *stack, int b_content)
{
	int		a_loc;
	int		min_idx;

	a_loc = -1;
	min_idx = 0;
	ra_cnt2(stack, b_content, &a_loc, &min_idx);
	if (a_loc == -1)
		a_loc = min_idx;
	if (a_loc > stack->a_size / 2)
		return (-(stack->a_size - a_loc));
	return (a_loc);
}

void	ra_cnt2(t_stack *stack, int b_content, int *a_loc, int *min_idx)
{
	int		i;
	int		diff;
	int		min;
	t_list	*tmp;

	i = 0;
	diff = 2147483647;
	min = 2147483647;
	tmp = stack->a_head;
	while (tmp)
	{
		if (tmp->content > b_content && tmp->content - b_content < diff)
		{
			diff = tmp->content - b_content;
			*a_loc = i;
		}
		if (min > tmp->content)
		{
			min = tmp->content;
			*min_idx = i;
		}
		i++;
		tmp = tmp->next;
	}
}

int	ft_abs(int value)
{
	if (value < 0)
		return (-(value));
	return (value);
}
