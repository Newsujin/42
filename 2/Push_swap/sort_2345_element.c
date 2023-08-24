/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2345_element.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 22:51:16 by spark2            #+#    #+#             */
/*   Updated: 2023/08/24 21:41:20 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2_contents(t_stack *stack)
{
	if (stack->a_head->content > stack->a_head->next->content)
		sa(stack, 0);
}

void	sort_3_contents(t_stack *stack)
{
	int	fst;
	int	scd;
	int	trd;

	fst = stack->a_head->content;
	scd = stack->a_head->next->content;
	trd = stack->a_bottom->content;
	while (!(fst < scd && scd < trd))
	{
		if (fst > scd && fst > trd)
			ra(stack, 0);
		else if (scd > trd)
			rra(stack, 0);
		else if (fst > scd)
			sa(stack, 0);
		fst = stack->a_head->content;
		scd = stack->a_head->next->content;
		trd = stack->a_bottom->content;
	}
}

void	sort_4_contents(t_stack *stack)
{
	int		idx;
	t_list	*tmp;

	idx = find_min(stack);
	while (1)
	{
		tmp = stack->a_head;
		if (tmp->content != stack->min)
		{
			if (idx > stack->a_size / 2)
				rra(stack, 0);
			else
				ra(stack, 0);
		}
		else
		{
			pb(stack);
			break ;
		}
	}
	sort_3_contents(stack);
	pa(stack);
}

void	sort_5_contents(t_stack *stack)
{
	move_2_element(stack);
	sort_3_contents(stack);
	pa(stack);
	pa(stack);
	if (stack->a_head->content > stack->a_head->next->content)
		sa(stack, 0);
}
