/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:22:35 by spark2            #+#    #+#             */
/*   Updated: 2023/08/25 21:16:48 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	*res;
	char	**res_split;
	t_stack	stack;

	if (argc < 2)
		return (1);
	res = combine_all_arg(argc, argv);
	res_split = ft_split(res, ' ', &argc);
	free(res);
	ft_memset(&stack, 0, sizeof(t_stack));
	setting(&stack, argc, res_split);
	pick_pivot(&stack);
	a_to_b(&stack);
	hard_coding(&stack);
	greedy(&stack);
	set_min_top(&stack);
	free_2d_array(argc, res_split, 0);
	free_stack(&stack, 0);
}
