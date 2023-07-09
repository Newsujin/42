/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 19:35:50 by spark2            #+#    #+#             */
/*   Updated: 2023/07/09 21:59:26 by spark2           ###   ########.fr       */
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
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	t_list	*a_head;
	t_list  *a_bottom;
	t_list	*b_head;
	t_list 	*b_bottom;
}	t_stack;

char	*ft_strdup(const char *src);
int		ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);

char	**ft_split_org(char const *s, char c, int *argc);

int		check_valid(char *str);
int		ft_atoi(const char *str);

t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst, t_list *new);
int		ft_lstadd_back(t_list **lst, t_list *new);

int		is_empty(t_stack *stack);
void	push_front(t_stack *stack, int item);
t_stack	*ft_stknew(t_list *a_head, t_list *a_bottom);

#endif