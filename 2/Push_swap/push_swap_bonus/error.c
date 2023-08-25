/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 20:19:10 by spark2            #+#    #+#             */
/*   Updated: 2023/08/25 22:10:33 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	finish(int argc, char **res_split, t_stack *stack, int flag, char *str)
{
	write(1, str, ft_strlen(str));
	free_2d_array(argc, res_split, 0);
	free_stack(stack, flag);
}
