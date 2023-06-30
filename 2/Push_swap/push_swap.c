/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 19:35:48 by spark2            #+#    #+#             */
/*   Updated: 2023/06/30 17:06:48 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_init(t_stack *stacks, int argc, char **argv)
{
	int		i;
	int		j;
	t_list	*head;
	t_list	*new;

	if (argc <= 1)
		return ;
	i = 0;
	while (++i < argc)
	{
		argv = ft_split(argv[i], &argc);
		if (!argv)
			return ;
		j = ft_atoi(argv[i]); //long 처리 필요
		if (i == 1)
			head = ft_lstnew(j);
		else
		{
			new = ft_lstnew(j);
			head->next = new;
			printf("new->content: %d\n", new->content);
			printf("new->next: %p\n", new->next);
			printf("===================\n");
		}
		printf("atoi한 값: %d\n", j);
		printf("head->content: %d\n", head->content);
		printf("head->next: %p\n", head->next);
	}
	stacks->a_head = head;
}

int	main(int argc, char *argv[])
{
	t_stack	stacks;

	ps_init(&stacks, argc, argv);
	//1. atoi로 받아온 인자 바꾸기 - 4 3 1 " 8 7"로 들어오면 뒤에 split해서 각각 인자값 받기
	//2. 스택에 바로 넣기 (연결리스트로 구성됨) - 중복 인자 체크
	// while (++i < argc)
	// {
	// 	printf("%d\n", new->content);
	// }
}