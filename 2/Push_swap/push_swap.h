/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 19:35:50 by spark2            #+#    #+#             */
/*   Updated: 2023/06/30 21:06:17 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	t_list	*a_head;
	t_list	*b_head;
	int		a_size;
}	t_stack;

int		ft_atoi(const char *str);
t_list	*ft_lstnew(int content);
char	**ft_split(char const **s, int *argc);

#endif