/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:03:01 by spark2            #+#    #+#             */
/*   Updated: 2023/08/20 20:26:12 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* stack a에 인자 5개만 남기고 pivot을 기준으로 pb or pb, rb */
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

/* stack b에서 stack a로 옮기는 데 비용이 가장 적게 드는 인자 선택 및 이동 */
void	b_to_a(t_stack *stack)
{
	int		i; //stack b의 인자를 하나씩 돌기 위해 필요한 변수
	int		a_idx; //ra or rra 횟수
	int		b_idx; //rb or rrb 횟수
	int		a_final; //찐 ra 횟수
	int		b_final; //찐 rb 횟수
	int		min; //ra + rb 최솟값
	t_list	*tmp;
	t_list	*debug;

	while (stack->b_size)
	{
		i = -1;
		min = 2147483647;
		tmp = stack->b_head;
		while (tmp)
		{
			b_idx = rb_cnt(stack, ++i);
			a_idx = ra_cnt(stack, tmp->content);
			printf("!!a_idx: %d\n", a_idx);
			if (ft_abs(b_idx) + ft_abs(a_idx) < min)
			{
				min = ft_abs(b_idx) + ft_abs(a_idx);
				a_final = a_idx;
				b_final = b_idx;
			}
			// printf("min: %d\n", min);
			printf("!!a_final: %d\n\n", a_final);
			// printf("b_final: %d\n\n\n", b_final);
			tmp = tmp->next;
		}
		//debug
		run_b_to_a(stack, a_final, b_final);
		debug = stack->a_head;
		while (debug)
		{
			printf("astack: %d\n", debug->content);
			debug = debug->next;
		}
		printf("=============\n");
		debug = stack->b_head;
		while (debug)
		{
			printf("bstack: %d\n", debug->content);
			debug = debug->next;
		}
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
	{
		a_loc = min_idx;
		printf("a_loc == 1 case > b_content: %d\n", b_content);
	}
	printf("a_loc = %d\n", a_loc);
	if (a_loc > stack->a_size / 2)
	{
		return (-(stack->a_size - a_loc));
	}
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
