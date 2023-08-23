/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:03:01 by spark2            #+#    #+#             */
/*   Updated: 2023/08/23 17:56:40 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* stack a에 인자 5개만 남기고 pivot을 기준으로 pb or pb, rb */
// void	a_to_b(t_stack *stack)
// {
// 	while (stack->a_size > 5)
// 	{
// 		if (stack->a_head->content < stack->pivot)
// 			pb(stack);
// 		else
// 		{
// 			pb(stack);
// 			rb(stack);
// 		}
// 		stack->a_size--;
// 		stack->b_size++;
// 	}
// }

void	a_to_b(t_stack *stack)
{
	int	i;

	i = -1;
	while (++i < stack->a_size + stack->b_size)
	{
		if (stack->a_head->content < stack->pivot1)
			ra(stack);
		else if (stack->a_head->content > stack->pivot2)
		{
			pb(stack);
			rb(stack);
			(stack->a_size)--;
			(stack->b_size)++;
		}
		else
		{
			pb(stack);
			(stack->a_size)--;
			(stack->b_size)++;
		}
	}
	while ((stack->a_size) > 5)
	{
		pb(stack);
		(stack->a_size)--;
		(stack->b_size)++;
	}
}

/* stack b에서 stack a로 옮기는 데 비용이 가장 적게 드는 인자 선택 및 이동 */
void	b_to_a(t_stack *stack)
{
	int		i; //stack b의 인자를 하나씩 돌기 위해 필요한 변수
	int		min; //ra + rb 최솟값
	t_list	*tmp;

	while (stack->b_size)
	{
		i = -1;
		min = 2147483647;
		tmp = stack->b_head;
		while (tmp)
		{
			stack->rb_count = rb_cnt(stack, ++i);
			stack->ra_count = ra_cnt(stack, tmp->content);
			if (ft_abs(stack->rb_count) + ft_abs(stack->ra_count) < min)
			{
				min = ft_abs(stack->rb_count) + ft_abs(stack->ra_count);
				stack->ra_final = stack->ra_count;
				stack->rb_final = stack->rb_count;
			}
			tmp = tmp->next;
		}
		run_b_to_a(stack, stack->ra_final, stack->rb_final);
		stack->b_size--;
		stack->a_size++;
	}
}

/* ra or rra 횟수 구하기 */
int	ra_cnt(t_stack *stack, int b_content)
{
	int		a_idx; //a stack 하나씩 돌아볼 변수
	int		a_loc; //ra or rra 할 위치
	int		diff; //stack a - stack b
	int		min; //a stack의 최솟값
	int		min_idx; //a stack의 최솟값의 idx
	t_list	*tmp;

	a_idx = 0;
	a_loc = -1;
	diff = 2147483647;
	min = 2147483647;
	min_idx = 0;
	tmp = stack->a_head;
	while (tmp)
	{
		//1. b 스택의 현재 인자보다 a 스택의 인자가 크다.
		//2. (a 스택의 인자 - b 스택의 인자) 중 최솟값이다.
		if (tmp->content > b_content && tmp->content - b_content < diff)
		{
			diff = tmp->content - b_content;
			a_loc = a_idx;
		}
		//a 스택의 최솟값 찾기
		if (min > tmp->content)
		{
			min = tmp->content;
			min_idx = a_idx;
		}
		a_idx++;
		tmp = tmp->next;
	}
	//a 스택에 있는 어떠한 값보다 b 스택의 현재 인자가 크다면 a 스택의 최솟값이 옮겨줄 자리
	if (a_loc == -1)
		a_loc = min_idx;
	if (a_loc > stack->a_size / 2)
		return (-(stack->a_size - a_loc));
	return (a_loc);
}

/* rb or rrb 횟수 구하기 */
int	rb_cnt(t_stack *stack, int idx)
{
	//내가 보고 있는 b stack의 값이 b_size / 2 보다 크다면 rrb
	if ((stack->b_size / 2) < idx)
		return (-(stack->b_size - idx));
	return (idx);
}
