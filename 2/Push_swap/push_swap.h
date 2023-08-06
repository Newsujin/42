/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 19:35:50 by spark2            #+#    #+#             */
/*   Updated: 2023/08/06 19:27:51 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	t_list	*a_head;
	t_list	*a_bottom;
	t_list	*b_head;
	t_list	*b_bottom;
}	t_stack;

//check valid
int		check_valid(char *str);
int		is_empty(t_list *node);

//lst func
t_list	*ft_lstnew(int content);
t_stack	*ft_stknew(t_list *a_head, t_list *a_bottom);
int		ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst, t_list *new);

//command
void	pa(t_stack *stack);
void	pb(t_stack *stack);
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack);

//split
void	*ft_free(char **ptr, int i);
int		cnt_word(const char *s, char c);
char	*ft_word_dup(char const *s, int idx, char c);
char	**ft_split_org(char const *s, char c, int *argc);

//utils
size_t	ft_strlen(const char *str);
int		ft_strchr(const char *s, int c);
int		ft_atoi(const char *str);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);

#endif