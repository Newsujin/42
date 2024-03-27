/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 22:35:44 by spark2            #+#    #+#             */
/*   Updated: 2023/08/24 22:35:55 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	numbering(t_stack stack, t_list *new)
{
	t_list	*cur;

	cur = stack.a_head;
	while (cur != new)
	{
		if (cur->content > new->content)
			cur->idx++;
		else
			new->idx++;
		cur = cur->next;
	}
}
