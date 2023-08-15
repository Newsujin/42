/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 21:47:19 by spark2            #+#    #+#             */
/*   Updated: 2023/08/15 21:45:34 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	pick_pivot(int min, int max, int cnt)
// {
// 	t_list	*tmp;

// 	*size = 0;
// 	tmp = stack->a_head;
// 	while (tmp)
// 	{
// 		tmp = tmp->next;
// 		(*size)++;
// 	}
// 	tmp = stack->a_head;
// 	while (tmp)
// 	{
// 		if (tmp->idx == *size / 3 + 1)
// 			*pivot1 = tmp->content;
// 		if (tmp->idx == (*size * 2) / 3 + 1)
// 			*pivot2 = tmp->content;
// 		tmp = tmp->next;
// 	}
// }

void	pick_pivot(t_stack *stack, int *pivot1, int *pivot2, int *size)
{
	t_list	*tmp;

	*size = 0;
	tmp = stack->a_head;
	while (tmp)
	{
		tmp = tmp->next;
		(*size)++;
	}
	tmp = stack->a_head;
	while (tmp)
	{
		if (tmp->idx == *size / 3 + 1)
			*pivot1 = tmp->content;
		if (tmp->idx == (*size * 2) / 3 + 1)
			*pivot2 = tmp->content;
		tmp = tmp->next;
	}
}

// void	a_to_b(t_stack *stack, int min, int max, int cnt)
void	a_to_b(t_stack *stack)
{
	int	size;
	int	pivot1;
	int	pivot2;
	// int	pivot[2];

	// pivot[0] = pick_pivot(min, max, cnt);
	// pivot[1] = pick_pivot(min, max, cnt);
	pick_pivot(stack, &pivot1, &pivot2, &size);
	printf("p1: %d\n", pivot1);
	printf("p2: %d\n", pivot2);

	//size를 세 뭉치 중 하나의 사이즈로 정의해야 함 (즉 세 뭉치로 나눈 다음 > 그 중 한 뭉치의 사이즈로 - 그래야 그 한 뭉치가 파고 파고 들어가서 사이즈가 3일 때가 나옴)
	if (size < 3)
	{
		//하드코딩
	}
	while (size)
	{
		//pivot을 인덱스로 잡으면 아래 비교를 어케 하나요?
		if (pivot2 <= stack->a_head->content)
		{
			ra(stack);
			stack->ra_count++;
		}
		else
		{
			pb(stack);
			stack->pb_count++;
			if (pivot1 <= stack->b_head->content)
			{
				rb(stack);
				stack->pb_count++;
			}
		}
		size--;
	}
	t_list *tmp = stack->a_head;
	t_list *tmp2 = stack->b_head;
	while (tmp)
	{
		printf("a content: %d\n", tmp->content);
		tmp = tmp->next;
	}
	while (tmp2)
	{
		printf("b content: %d\n", tmp2->content);
		tmp2 = tmp2->next;
	}
	a_to_b(stack);
}
