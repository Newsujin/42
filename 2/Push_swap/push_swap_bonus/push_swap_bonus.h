/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 19:35:50 by spark2            #+#    #+#             */
/*   Updated: 2023/08/28 12:40:25 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "get_next_line.h"

typedef struct s_list
{
	int				content;
	int				idx;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	t_list	*a_head;
	t_list	*a_bottom;
	t_list	*b_head;
	t_list	*b_bottom;
	int		pivot1;
	int		pivot2;
	int		ra_count;
	int		rb_count;
	int		ra_final;
	int		rb_final;
	int		a_size;
	int		b_size;
	int		min;
	int		wrong_elmt;
}	t_stack;

//array
char	*combine_all_arg(int argc, char **argv);
char	**ft_split(char *s, char c, int *argc);
int		cnt_word(char *s, char c);
char	**spliting(int *j, char c, char *s, char **ptr);
char	*ft_word_dup(char *s, int idx, char c);

//setting
void	*ft_memset(void *arr, int value, size_t len);
void	setting(t_stack *stack, int argc, char **res_split);
int		check_valid(char *str);
void	init_stack(int argc, char **res_split, t_stack *stack);
int		check_sorted(t_stack *stack);

//pivot, indexing
void	numbering(t_stack stack, t_list *new);

//lst func
t_list	*ft_lstnew(int content);
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
void	rr(t_stack *stack);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack);

//final_arrange
void	set_min_top(t_stack *stack);
int		find_first_value(t_stack *stack);

//utils
size_t	ft_strlen(const char *str);
int		is_only_space(const char *s, int c);
int		ft_atoi(const char *str);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_abs(int value);

//free
void	free_split(char **ptr, int i);
void	free_array(char *str);
void	free_2d_array(int argc, char **str, int flag);
void	free_stack(t_stack *stack, int flag);

//bonus
void	run_command1(t_stack *stack, char *str);
void	gnl_cmp(t_stack *stack, int argc, char **res_split);
void	finish_normal(int argc, char **res_split, t_stack *stack, char *str);
void	finish_error(int argc, char **res_split, t_stack *stack, char *str);

#endif