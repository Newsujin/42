/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 22:08:49 by spark2            #+#    #+#             */
/*   Updated: 2023/08/26 16:13:30 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int argc, char **argv)
{
	char	*res;
	char	**res_split;
	t_stack	stack;

	if (argc < 2)
		return (0);
	res = combine_all_arg(argc, argv);
	res_split = ft_split(res, ' ', &argc);
	free(res);
	ft_memset(&stack, 0, sizeof(t_stack));
	setting(&stack, argc, res_split);
	gnl_cmp(&stack, argc, res_split);
	if (!check_sorted(&stack))
		finish_error(argc, res_split, &stack, "KO\n");
	if (stack.b_head)
		finish_error(argc, res_split, &stack, "KO\n");
	finish_normal(argc, res_split, &stack, "OK\n");
	return (0);
}
