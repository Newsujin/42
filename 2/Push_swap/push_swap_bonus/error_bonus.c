/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 20:19:10 by spark2            #+#    #+#             */
/*   Updated: 2023/08/26 15:45:14 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	finish_normal(int argc, char **res_split, t_stack *stack, char *str)
{
	write(1, str, ft_strlen(str));
	free_2d_array(argc, res_split, 0);
	free_stack(stack, 0);
}

void	finish_error(int argc, char **res_split, t_stack *stack, char *str)
{
	write(1, str, ft_strlen(str));
	free_2d_array(argc, res_split, 0);
	free_stack(stack, 1);
}
