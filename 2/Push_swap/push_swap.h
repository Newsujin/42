/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 19:35:50 by spark2            #+#    #+#             */
/*   Updated: 2023/08/23 20:10:45 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

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
	// int		pivot;
	int		ra_count; //ra or rra 횟수
	int		rb_count; //rb or rrb 횟수
	int		ra_final; //최종 ra or rra 횟수
	int		rb_final; //최종 rb or rrb 횟수
	int		a_size;
	int		b_size;
	int		min;
}	t_stack;

//setting
void	setting(t_stack *stack, int argc, char **res_split);
int		check_valid(char *str);

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
int		is_only_space(const char *s, int c);
int		ft_atoi(const char *str);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);

//numbering
void	numbering(t_stack stack, t_list *new);

//sort
void	pick_pivot(t_stack *stack);
void	a_to_b(t_stack *stack);
void	hard_coding(t_stack *stack);
int		ra_cnt(t_stack *stack, int b_idx);
int		rb_cnt(t_stack *stack, int idx);
void	b_to_a(t_stack *stack);
void	run_b_to_a(t_stack *stack, int ra_cnt, int rb_cnt);

//etc
int		ft_abs(int value);
void	*ft_memset(void *arr, int value, size_t len);

//final
void	set_min_top(t_stack *stack);

//already sorted
int		check_already_sorted(t_stack *stack);

//combine
char	*combine_all_arg(int argc, char **argv);

void	free_stack(t_stack *stack);

#endif