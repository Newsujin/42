/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 21:47:19 by spark2            #+#    #+#             */
/*   Updated: 2023/08/23 17:52:47 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pick_pivot(t_stack *stack)
{
	t_list	*tmp;

	tmp = stack->a_head;
	while (tmp)
	{
		// if (tmp->idx == stack->a_size / 2)
		// 	stack->pivot = tmp->content;
		if (tmp->idx == stack->a_size / 3)
			stack->pivot1 = tmp->content;
		else if (tmp->idx == (stack->a_size) * 2 / 3)
			stack->pivot2 = tmp->content;
		tmp = tmp->next;
	}
}
