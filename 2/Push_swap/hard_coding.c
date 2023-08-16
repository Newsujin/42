/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_coding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 22:01:19 by spark2            #+#    #+#             */
/*   Updated: 2023/08/16 22:53:12 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2_contents(t_stack *stack)
{
	if (stack->a_head->content > stack->a_head->next->content)
		sa(stack);
}

void	sort_3_contents(t_stack *stack)
{
	// t_stack	*tmp;
	int fst;
	int scd;
	int trd;

	fst = stack->a_head->content;
	scd = stack->a_head->next->content;
	trd = stack->a_bottom->content;
	while (!(fst < scd && scd < trd))
	{
		fst = stack->a_head->content;
		scd = stack->a_head->next->content;
		trd = stack->a_bottom->content;
		if (fst > scd && fst > trd)
			ra(stack);
		else if (scd > trd)
			rra(stack);
		else if (fst > scd)
		{
			printf("here\n");
			sa(stack);
		}
	}
}

void	hard_coding(t_stack *stack)
{
	if (stack->a_size == 1)
		return ;
	else if (stack->a_size == 2)
	{
		sort_2_contents(stack);
		return ;
	}
	else if (stack->a_size == 3)
	{
		sort_3_contents(stack);
		return ;
	}
}
