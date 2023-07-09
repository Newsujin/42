/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:22:35 by spark2            #+#    #+#             */
/*   Updated: 2023/07/09 21:59:15 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

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
			return (-1);
		res = ft_strjoin(tmp, argv[i]);
		free(tmp);
		tmp = res;
		res = ft_strjoin(tmp, " ");
		free(tmp);
	}
	printf("res: %s\n", res);
	//인자를 공백 기준으로 split
	res_split = ft_split_org(res, ' ', &argc);
	// free(res);
	//유효성 체크
	i = -1;
	while (++i < argc)
	{
		if (!check_valid(res_split[i]))
		{
			printf("valid Error!\n");
			return (-1);
		}
	}
	//atoi
	i = -1;
	while (++i < argc)
	{
		num = ft_atoi(res_split[i]);
		if (i == 0)
			head = ft_lstnew(num);
		else
		{
			new = ft_lstnew(num);
			if (!ft_lstadd_back(&head, new))
				return (printf("dup Error!\n"));
		}
	}
	stack = ft_stknew(head, new);

	// while (head->next)
	// {
	// 	printf("content: %d\n", head->content);
	// 	head = head->next;
	// }
	// printf("content: %d\n", head->content);
	printf("stack->a_head: %p\n", stack->a_head);
	push_front(stack, 4);
	printf("stack->a_head: %p\n", stack->a_head);
	// system("leaks push_swap");
}