/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:22:35 by spark2            #+#    #+#             */
/*   Updated: 2023/08/04 22:32:22 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

// void	a_to_b(t_stack stack, int size)
// {
// 	int pivot1;
// 	int pivot2;
// 	int ra_count = 0;
// 	int pb_count = 0;
// 	int rb_count = 0;
// 	if (size <= 3)
// 	{
// 		//3개 이하 일  때 정렬 , 2개 1개도 되어야함.
// 	}
// 	//퀵소트의 제일 빛 ㅋㅋ
// 	//피봇 2개 구하기
// 	//퀵소트 간단 설명 -> 숫자들이 들어오면 거기서 자기 맘대로(코딩하는 사람) 피봇을 정해서 정렬을 함 찾아보면 좋을 듯
// 	//우리는 push_swap 과제에서 퀵소트를 사용하는데 피봇 1개로는 push_swap을 통과 못 함. 왜?
// 	//push_swap 평가는 정렬되는 명령어의 개수를 통해 하게됨. 피봇 1개로는 절대 불가능 그래서 피봇 2개를 정해서 최적화를 해준다
// 	//피봇 2개 퀵소트 알고리즘(a_to_b 함수)
// 	//1. a스택에 만약 20개의 인자가 들어왔다가 가정
// 	//2. 피봇 2개를 구함 -> 3개의 구간으로 나뉨.
// 	//3. 이 구간을 통해서 a스택에서 피봇1과 피봇2 기준으로 b스택에 넣어줄 것임.
// 	//4. 피봇 1보다 큰 친구들은 a스택에 남겨놓고 나머지는 b스택에 옮김.
// 	//5. b스택에 옮겼을 때 만약 피봇 2보다 큰 친구들은 rb를 시켜 밑에 놓을 것임
// 	//이 과정을 거치면 a스택에는 큰 친구들이 남고 b스택에는 밑 부분이 중간 친구들 윗부분이 작은 친구들이 남을 것임.
// 	//2, 3, 4, 5 과정을 a스택에 인자가 3개 이하가 남을 때까지 a_to_b 재귀를 돌릴 것임.

// 	// 2과정 피봇 구하기

// 	// 피봇 구하는 방법 2가지
// 	// 퀵소트는 랜덤이라고 했지만 여기서는 랜덤으로 하면 안됨 왜냐? 정렬을 할 때 최악의 경우를 생각하면 명령어가 엄청 나옴
// 	// ex > 리스트가 100개 있는데 제일 마지막을 피봇으로 잡아버리면 while을 99번 돌아아함.
// 	// 첫 번째 방법 -> 누나가 스택에 담겨있는 t_list에 그 친구들의 순위를 매겨준다.
// 	// 재윤이가 한 방법이기도 한 두 번째 방법 -> select_pivot 함수에 리스트 size를 넘겨준 후 거기서 순위를 구함
// 	// 순위가 곧 피봇의 값이 되는 거임 -> index 자리

// 	//피봇 구할 때는 리스트 안에 있는 값들로 정해야함 무조건!
// 	//pivot을 구할 때의 알고리즘 자기 맘대로 해주기
// 	pivot1 = select_pivot1();
// 	pivot2 = select_pivot2();

// 	//3과정
// 	//여기서 또 주의해야 할 점 퀵소트는 피봇의 값에 따라 정렬 하는 시간 복잡도가 달라짐 그래서 pivot1과
// 	//pivot2 친구들을 포함 시킬 거냐 안 시킬 거냐도 중요함
// 	//재윤이가 해준 거는 piovt1 포함 -> pivot1도 큰 친구들에 포함 된다는 말임. , piovt2 포함 -> pivot2도 중간 친구들에 포함 된다는 말임.
// 	while (size)
// 	{
// 		if (pivot1 <= (*stack)->a_head->content)
// 		{
// 			ra();
// 			ra_count++;
// 		}
// 		else
// 		{
// 			pb();
// 			pb_count++;
// 			if (pivot2 <= (*stack)->b_head->content)
// 			{
// 				rb();
// 				rb_count++;
// 			}
// 		}
// 		size--;
// 	}
// 	a_to_b(ra_count);
// 	// 재귀까지 다 돌면
// 	// |		|   |		 |
// 	// | 		|	|작은 친구들|
// 	// |		|	|		 |
// 	// |		|	|		 |
// 	// |		|	|		 |
// 	// |		|	|		 |
// 	// |큰 친구들 |	  | 중간 친구들|
// 	//  --------	--------
// 	// a스택         b스택
// 	// 이런 구조가 완료됨
// }

// void	sorting_ing(t_stack **stack)
// {
// 	int stack_size = 0;
// 	t_list *tmp;

// 	tmp = (*stack)->a_head;
// 	while (tmp)
// 	{
// 		stack_size++;
// 		tmp = tmp->next;
// 	}
// 	//printf("%d", stack_size);
// 	a_to_b(stack, stack_size);
// }

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
	t_list	*head;
	t_list	*new;
	t_stack	*stack;

	//인자를 공백과 함께 strjoin으로 전부 붙이기
	i = 0;
	res = ft_strdup("");
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
		if (!check_valid(res_split[i]))
			return (printf("valid Error!\n"));
	}
	//atoi
	i = -1;
	while (++i < argc)
	{
		num = ft_atoi(res_split[i]);
		if (i == 0)
		{
			head = ft_lstnew(num); //첫번째 인자는 head에 생성
			if (!head)
				return (printf("malloc error!\n"));
		}
		else
		{
			new = ft_lstnew(num); //나머지 인자들은 new에 생성
			if (!new)
				return (printf("malloc error!\n"));
			if (!ft_lstadd_back(&head, new)) //head 뒤에 인자들 붙이기
				return (printf("dup Error!\n"));
		}
	}
	// stack 생성
	stack = ft_stknew(head, new);
	if (!stack)
		return (printf("dup Error!\n"));

	// push
	// push_a(stack);
	// while (stack->a_head)
	// {
	// 	printf("%d\n", stack->a_head->content);
	// 	printf("%p\n", stack->a_head);
	// 	printf("%p\n", stack->a_head->next);
	// 	stack->a_head = stack->a_head->next;
	// }
	// push_b(stack);
	// while (stack->b_head)
	// {
	// 	printf("%d\n", stack->b_head->content);
	// 	printf("%p\n", stack->b_head);
	// 	printf("%p\n", stack->b_head->next);
	// 	stack->b_head = stack->b_head->next;
	// 	printf("\n\n");
	// }
	// printf("====================\n");


	// // swap
	// printf("a_head->content: %d\n", stack->a_head->content);
	// printf("a_head->next->content: %d\n", stack->a_head->next->content);
	// printf("a_head: %p\n", stack->a_head);
	// printf("a_head->next: %p\n", stack->a_head->next);
	// printf("a_head->next->next: %p\n", stack->a_head->next->next);
	// printf("---------------------------------\n");
	// swap_a(stack);
	// printf("a_head->content: %d\n", stack->a_head->content);
	// printf("a_head->next->content: %d\n", stack->a_head->next->content);
	// printf("a_head: %p\n", stack->a_head);
	// printf("a_head->next: %p\n", stack->a_head->next);
	// printf("a_head->next->next: %p\n", stack->a_head->next->next);
	// printf("---------------------------------\n");

	// printf("b_head->content: %d\n", stack->b_head->content);
	// printf("b_head->next->content: %d\n", stack->b_head->next->content);
	// printf("b_head: %p\n", stack->b_head);
	// printf("b_head->next: %p\n", stack->b_head->next);
	// printf("b_head->next->next: %p\n", stack->b_head->next->next);

	// swap_b(stack);
	// printf("---------------------------------\n");
	// printf("b_head->content: %d\n", stack->b_head->content);
	// printf("b_head->next->content: %d\n", stack->b_head->next->content);
	// printf("b_head: %p\n", stack->b_head);
	// printf("b_head->next: %p\n", stack->b_head->next);
	// printf("b_head->next->next: %p\n", stack->b_head->next->next);

	//rotate
	// rotate_a(stack);
	ss(stack);
	while (stack->b_head)
	{
		printf("a_head->content: %d\n", stack->b_head->content);
		printf("a_head's addr: %p\n", stack->b_head);
		printf("===============================\n");
		stack->b_head = stack->b_head->next;
	}
	printf("\n\n");
	while (stack->a_head)
	{
		printf("a_head->content: %d\n", stack->a_head->content);
		printf("a_head's addr: %p\n", stack->a_head);
		printf("===============================\n");
		stack->a_head = stack->a_head->next;
	}
	// rotate_b(stack);
	// while (stack->b_head)
	// {
	// 	printf("a_head->content: %d\n", stack->b_head->content);
	// 	printf("a_head's addr: %p\n", stack->b_head);
	// 	stack->b_head = stack->b_head->next;
	// }
	// sorting_ing(&stack);
	// atexit(_leaks);
}