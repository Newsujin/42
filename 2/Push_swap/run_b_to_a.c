/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_b_to_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:15:54 by spark2            #+#    #+#             */
/*   Updated: 2023/08/20 17:03:15 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	run_b_to_a(t_stack *stack, int ra_cnt, int rb_cnt)
{
	//음수라면 rrb 아니면 rb
	if (rb_cnt < 0)
	{
		rb_cnt = -rb_cnt;
		while (rb_cnt)
		{
			rrb(stack);
			rb_cnt--;
		}
	}
	else
	{
		while (rb_cnt)
		{
			rb(stack);
			rb_cnt--;
		}
	}
	if (ra_cnt < 0)
	{
		ra_cnt = -ra_cnt;
		while (ra_cnt)
		{
			rra(stack);
			ra_cnt--;
		}
	}
	else
	{
		while (ra_cnt)
		{
			ra(stack);
			ra_cnt--;
		}
	}
	pa(stack);
}
