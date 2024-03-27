/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:12:08 by spark2            #+#    #+#             */
/*   Updated: 2023/08/24 22:57:25 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **ptr, int i)
{
	while (i >= 0)
		free(ptr[i--]);
	free(ptr);
}

void	free_array(char *str)
{
	free(str);
	exit(1);
}

void	free_2d_array(int argc, char **str, int flag)
{
	int	i;

	i = -1;
	while (++i < argc)
		free(str[i]);
	free(str);
	if (flag == 1)
		exit(1);
}

void	free_stack(t_stack *stack, int flag)
{
	t_list	*tmp;
	t_list	*node;

	node = stack->a_head;
	while (node)
	{
		tmp = node->next;
		free(node);
		node = 0;
		node = tmp;
	}
	node = stack->b_head;
	while (node)
	{
		tmp = node->next;
		free(node);
		node = 0;
		node = tmp;
	}
	if (flag == 1)
		exit(1);
	exit(0);
}
