/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_coding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 22:01:19 by spark2            #+#    #+#             */
/*   Updated: 2023/08/20 22:56:41 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sort_2_contents(t_stack *stack)
{
	if (stack->a_head->content > stack->a_head->next->content)
		sa(stack);
}

void	sort_3_contents(t_stack *stack)
{
	int fst;
	int scd;
	int trd;

	fst = stack->a_head->content;
	scd = stack->a_head->next->content;
	trd = stack->a_bottom->content;
	while (!(fst < scd && scd < trd))
	{
		if (fst > scd && fst > trd)
			ra(stack);
		else if (scd > trd)
			rra(stack);
		else if (fst > scd)
			sa(stack);
		fst = stack->a_head->content;
		scd = stack->a_head->next->content;
		trd = stack->a_bottom->content;
	}
}

void	sort_4_contents(t_stack *stack)
{
	int		idx; //pb할 인자의 idx
	t_list	*tmp;

	idx = find_min(stack);
	while (1)
	{
		tmp = stack->a_head;
		//최솟값이 아니면 넘기기
		if (tmp->content != stack->min)
		{
			//인덱스가 사이즈 / 2 보다 크다면 rra
			if (idx > stack->a_size / 2)
				rra(stack);
			else
				ra(stack);
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
	int		cnt;
	int		idx;
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
	sort_3_contents(stack);
	pa(stack);
	pa(stack);
	if (stack->a_head->content > stack->a_head->next->content)
		sa(stack);
}

void	hard_coding(t_stack *stack)
{
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
