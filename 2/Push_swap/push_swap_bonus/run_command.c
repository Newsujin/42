/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 16:32:41 by spark2            #+#    #+#             */
/*   Updated: 2023/08/25 22:08:52 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	gnl_cmp(t_stack *stack)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		run_command1(stack, line);
		free(line);
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// void	wrong_element(t_stack *stack, char *str, char ***res_split)
// {
// 	write(1, "Error\n", 6);
// 	// free_2d_array(argc, res_split, 0);
// 	free(stack, 1);
// }

void	run_command2(t_stack *stack, char *str)
{
	if (!(ft_strcmp(str, "ra\n")))
		ra(stack);
	else if (!(ft_strcmp(str, "rb\n")))
		rb(stack);
	else if (!(ft_strcmp(str, "rr\n")))
		rr(stack);
	else if (!(ft_strcmp(str, "rra\n")))
		rra(stack);
	else if (!(ft_strcmp(str, "rrb\n")))
		rrb(stack);
	else if (!(ft_strcmp(str, "rrr\n")))
		rrr(stack);
	else
		exit(1);
}

void	run_command1(t_stack *stack, char *str)
{
	if (!(ft_strcmp(str, "pa\n")))
		pa(stack);
	else if (!(ft_strcmp(str, "pb\n")))
		pb(stack);
	else if (!(ft_strcmp(str, "sa\n")))
		sa(stack);
	else if (!(ft_strcmp(str, "sb\n")))
		sb(stack);
	else if (!(ft_strcmp(str, "ss\n")))
		ss(stack);
	else
		run_command2(stack, str);
}
