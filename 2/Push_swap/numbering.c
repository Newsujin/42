/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:16:26 by spark2            #+#    #+#             */
/*   Updated: 2023/08/07 21:55:00 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//list 인덱스 번호로 넘버링하기
void	numbering(t_list *head, t_list *new)
{
	t_list	*cur;

	cur = head;
	while (cur != new)
	{
		if (cur->content > new->content)
			cur->idx++;
		else
			new->idx++;
		cur = cur->next;
	}
}
