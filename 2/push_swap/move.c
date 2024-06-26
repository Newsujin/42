/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 22:30:47 by spark2            #+#    #+#             */
/*   Updated: 2023/08/24 21:41:09 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_to_b(t_stack *stack)
{
	int	i;

	i = -1;
	if (stack->a_size > 5)
	{
		while (++i < stack->a_size + stack->b_size)
		{
			if (stack->a_head->content < stack->pivot1)
				ra(stack, 0);
			else if (stack->a_head->content > stack->pivot2)
			{
				pb(stack);
				rb(stack, 0);
				stack->a_size--;
				stack->b_size++;
			}
			else
			{
				pb(stack);
				stack->a_size--;
				stack->b_size++;
			}
		}
	}
}

void	b_to_a(t_stack *stack, int ra_cnt, int rb_cnt)
{
	run_rb(stack, rb_cnt);
	run_ra(stack, ra_cnt);
	pa(stack);
}

void	run_rb(t_stack *stack, int rb_cnt)
{
	if (rb_cnt < 0)
	{
		rb_cnt = -rb_cnt;
		while (rb_cnt)
		{
			rrb(stack, 0);
			rb_cnt--;
		}
	}
	else
	{
		while (rb_cnt)
		{
			rb(stack, 0);
			rb_cnt--;
		}
	}
}

void	run_ra(t_stack *stack, int ra_cnt)
{
	if (ra_cnt < 0)
	{
		ra_cnt = -ra_cnt;
		while (ra_cnt)
		{
			rra(stack, 0);
			ra_cnt--;
		}
	}
	else
	{
		while (ra_cnt)
		{
			ra(stack, 0);
			ra_cnt--;
		}
	}
}
