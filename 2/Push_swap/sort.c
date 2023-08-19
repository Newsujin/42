/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:03:01 by spark2            #+#    #+#             */
/*   Updated: 2023/08/19 19:06:01 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_to_b(t_stack *stack)
{
	while (stack->a_size > 5)
	{
		if (stack->a_head->content < stack->pivot)
			pb(stack);
		else
		{
			pb(stack);
			rb(stack);
		}
		stack->a_size--;
		stack->b_size++;
	}
}

int	rb_cnt(t_stack *stack, int idx)
{
	if ((stack->b_size / 2) < idx) //내가 보고 있는 b stack의 값이 b_size / 2 보다 크다면 rrb
		return (-(stack->b_size - idx));
	return (idx);
}

void	b_to_a(t_stack *stack)
{
	int		a_idx; //ra or rra 횟수
	int		b_idx; //rb or rrb 횟수
	int		i; //stack b의 인자 보는 순서
	t_list	*tmp;

	i = -1;
	tmp = stack->b_head;
	while (tmp)
	{
		b_idx = rb_cnt(stack, ++i);
		a_idx = ra_cnt(stack);
		tmp = tmp->next;
	}
}
