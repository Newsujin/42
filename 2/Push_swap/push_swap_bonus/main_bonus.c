/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 22:08:49 by spark2            #+#    #+#             */
/*   Updated: 2023/08/25 22:09:19 by spark2           ###   ########.fr       */
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
	gnl_cmp(&stack);
	if (!check_sorted(&stack))
		finish(argc, res_split, &stack, 1, "KO\n");
	if (stack.b_head)
		finish(argc, res_split, &stack, 1, "KO\n");
	finish(argc, res_split, &stack, 0, "OK\n");
	// atexit(_leaks);
	return (0);
}

// void	_leaks()
// {
// 	system("leaks checker");
// }
