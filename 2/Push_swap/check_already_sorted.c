/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_already_sorted.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 21:16:44 by spark2            #+#    #+#             */
/*   Updated: 2023/08/22 20:27:48 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_already_sorted(t_stack *stack)
{
	t_list	*tmp;

	tmp = stack->a_head;
	while (tmp->next)
	{
		if (tmp->idx > tmp->next->idx)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
