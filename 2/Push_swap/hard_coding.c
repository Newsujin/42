/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_coding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 22:01:19 by spark2            #+#    #+#             */
/*   Updated: 2023/08/19 15:44:23 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_max(t_stack *stack, int flag)
{
	int		value;
	t_list	*tmp;

	tmp = stack->a_head;
	if (flag == 0) //find min
	{
		value = 2147483647;
		while (tmp)
		{
			if (tmp->content < value)
				value = tmp->content;
			tmp = tmp->next;
		}
	}
	else //find max
	{
		value = -2147483648;
		while (tmp)
		{
			if (tmp->content > value)
				value = tmp->content;
			tmp = tmp->next;
		}
	}
	return (value);
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
	int		min;
	t_list	*tmp;

	min = find_min_max(stack, 0);
	tmp = stack->a_head;
	while (tmp)
	{
		if (tmp->content != min)
			ra(stack);
		else
		{
			pb(stack);
			break ;
		}
		tmp = tmp->next;
	}
	sort_3_contents(stack);
	pa(stack);
}

void	sort_5_contents(t_stack *stack)
{
	int		min;
	int		max;
	int		cnt;
	t_list	*tmp;

	min = find_min_max(stack, 0);
	max = find_min_max(stack, 1);
	cnt = 0;
	tmp = stack->a_head;
	while (tmp)
	{
		if (tmp->content == min || tmp->content == max)
		{
			pb(stack);
			cnt++;
		}
		else
			ra(stack);
		tmp = stack->a_head;
		if (cnt == 2)
			break ;
	}
	sort_3_contents(stack);
	pa(stack);
	pa(stack);
	if (stack->a_head->content < stack->a_head->next->content)
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
