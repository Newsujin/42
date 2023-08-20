/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:22:35 by spark2            #+#    #+#             */
/*   Updated: 2023/08/20 23:08:39 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	_leaks()
{
	system("leaks push_swap");
}

int	main(int argc, char **argv)
{
	int		i;
	int		num;
	char	*res;
	char	*tmp;
	char	**res_split;
	t_list	*new;
	t_list	*stack_tmp;
	t_stack	stack;

	//stack 초기화 함수 빼기
	// stack.a_head = NULL;
	// stack.a_bottom = NULL;
	// stack.b_head = NULL;
	// stack.b_bottom = NULL;
	// stack.a_size = 0;
	// stack.b_size = 0;
	ft_memset(&stack, 0, sizeof(t_stack));
	printf("stack.ahead: %p\n", stack.a_head);
	printf("stack.a_bottom: %p\n", stack.a_bottom);
	printf("stack.bhead: %p\n", stack.b_head);
	printf("stack.b_bottom: %p\n", stack.b_bottom);
	printf("stack.a_size: %d\n", stack.a_size);
	printf("stack.b_size: %d\n", stack.b_size);
	//인자를 공백과 함께 strjoin으로 전부 붙이기
	i = 0;
	res = ft_strdup("");
	if (argc == 1)
		return 1;
	while (++i < argc)
	{
		tmp = res;
		if (!ft_strchr(argv[i], ' ')) //argv가 공백으로만 구성되어 있으면 에러
			return (printf("only space Error!\n"));
		res = ft_strjoin(tmp, argv[i]); //인자를 공백과 함께 res에 붙이기
		free(tmp);
	}
	printf("res: %s\n", res);
	//인자를 공백 기준으로 split
	res_split = ft_split_org(res, ' ', &argc);
	free(res);
	//유효성 체크
	i = -1;
	while (++i < argc)
	{
		//check_valid를 atoi랑 합쳐도 될 듯 !!!!
		if (!check_valid(res_split[i]))
			return (printf("valid Error!\n"));
	}
	//atoi & lst add
	i = -1;
	while (++i < argc)
	{
		num = ft_atoi(res_split[i]);
		if (i == 0)
		{
			stack.a_head = ft_lstnew(num); //첫번째 인자는 head에 생성
			if (!stack.a_head)
				return (printf("malloc error!\n"));
		}
		else
		{
			new = ft_lstnew(num); //나머지 인자들은 new에 생성
			if (!new)
				return (printf("malloc error!\n"));
			if (!ft_lstadd_back(&stack.a_head, new)) //stack.a_head 뒤에 인자들 붙이기
				return (printf("dup Error!\n"));
			numbering(stack, new); //인덱싱하기
		}
	}
	stack.a_bottom = new;
	stack.a_size = argc; //처음엔 argc 만큼이 a 스택의 크기임
	pick_pivot(&stack);
	printf("pv: %d\n", stack.pivot);
	a_to_b(&stack);
	hard_coding(&stack);
	printf("before b_to a!\n\n");
	b_to_a(&stack);
	set_min_top(&stack);
	stack_tmp = stack.a_head;
	while (stack_tmp)
	{
		printf("astack: %d\n", stack_tmp->content);
		stack_tmp = stack_tmp->next;
	}
	printf("=============\n");
	stack_tmp = stack.b_head;
	while (stack_tmp)
	{
		printf("bstack: %d\n", stack_tmp->content);
		stack_tmp = stack_tmp->next;
	}
	// atexit(_leaks);
}

//stack의 bottom 없애고 명령어들 수정하기