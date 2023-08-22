/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:22:35 by spark2            #+#    #+#             */
/*   Updated: 2023/08/22 22:43:18 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	_leaks()
{
	system("leaks push_swap");
}

int	main(int argc, char **argv)
{
	char	*res;
	char	**res_split;
	t_stack	stack;

	if (argc < 2)
		return (1);
	res = combine_all_arg(argc, argv);
	res_split = ft_split_org(res, ' ', &argc);
	free(res);
	ft_memset(&stack, 0, sizeof(t_stack));
	setting(&stack, argc, res_split);
	pick_pivot(&stack);
	a_to_b(&stack);
	hard_coding(stack);
	b_to_a(&stack);
	set_min_top(&stack);

	// printf("pv1: %d\n", stack.pivot1);
	// printf("pv2: %d\n", stack.pivot2);
	//debug
	// t_list	*stack_tmp;
	// stack_tmp = stack.a_head;
	// while (stack_tmp)
	// {
	// 	printf("astack: %d\n", stack_tmp->content);
	// 	stack_tmp = stack_tmp->next;
	// }
	// printf("=============\n");
	// stack_tmp = stack.b_head;
	// while (stack_tmp)
	// {
	// 	printf("bstack: %d\n", stack_tmp->content);
	// 	stack_tmp = stack_tmp->next;
	// }
	// atexit(_leaks);
}

//stack의 bottom 없애고 명령어들 수정하기
//이미 정렬되어 있다면 정렬 안 하기