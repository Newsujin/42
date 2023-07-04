/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:22:35 by spark2            #+#    #+#             */
/*   Updated: 2023/07/04 22:56:36 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	int		num;
	t_list	*head;
	t_list	*new;
	// t_list	*tmp;
	char	*res;
	char	*tmp;
	char	**res_split;

	//인자 공백과 함께 strjoin으로 전부 붙이기
	i = 0;
	res = ft_strdup("");
	while (++i < argc)
	{
		tmp = res;
		res = ft_strjoin(tmp, argv[i]);
		free(tmp);
		tmp = res;
		res = ft_strjoin(tmp, " ");
		free(tmp);
	}
	//인자를 공백 기준으로 split
	i = 0;
	printf ("tmp = %s\n", tmp);
	res_split = ft_split_org(tmp, ' ');
	printf("next split = %s\n", res_split[1]);
	while (i < argc)
	{
		printf("res_split:%s\n", res_split[i]);
		// free(res);
		i++;
	}
	// system("leaks a.out");

	// while (++i < argc)
	// {
	// 	num = ft_atoi(argv[i]);
	// 	if (i == 1)
	// 	{
	// 		head = ft_lstnew(num);
	// 		printf("head->content: %d\n", head->content);
	// 		printf("head->next: %p\n", head->next);
	// 	}
	// 	else
	// 	{
	// 		new = ft_lstnew(num);
	// 		head->next = new;
	// 		printf("new->content: %d\n", new->content);
	// 		printf("new->next: %p\n", new->next);
	// 	}
	// 	printf("atoi한 값: %d\n", num);
	// 	printf("argc: %d\n", argc);
	// 	printf("argv[i]: %s\n", argv[i]);
	// 	printf("======================\n");
	// }
}