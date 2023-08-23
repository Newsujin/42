/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 20:33:17 by spark2            #+#    #+#             */
/*   Updated: 2023/08/23 21:26:03 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_memset(void *arr, int value, size_t len)
{
	size_t			i;
	unsigned char	*temp;

	temp = (unsigned char *)arr;
	i = 0;
	while (i < len)
		temp[i++] = value;
	return (temp);
}

void	setting(t_stack *stack, int argc, char **res_split)
{
	int		i;

	i = -1;
	while (++i < argc)
	{
		if (!check_valid(res_split[i]))
			free_array(argc, res_split); //인자로 받아 free하려면 포인터가 필요한데, 그러면 ***res_split..?
	}
	init_stack(argc, res_split, stack);
	stack->a_size = argc;
	if (check_already_sorted(stack))
		free_stack(stack);
}

/* +, -, 빈 문자, 숫자, int 범위 체크 */
int	check_valid(char *str)
{
	int			i;
	int			sign;
	long long	res;

	i = 0;
	sign = 1;
	res = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		res = res * 10 + str[i] - '0';
		i++;
		if (res * sign > 2147483647 || res * sign < -2147483648)
			return (0);
	}
	return (1);
}

/* atoi & put element to stack */
void	init_stack(int argc, char **res_split, t_stack *stack)
{
	int		i;
	int		num;
	t_list	*new;

	i = -1;
	while (++i < argc)
	{
		num = ft_atoi(res_split[i]);
		if (i == 0)
		{
			stack->a_head = ft_lstnew(num);
			if (!stack->a_head)
				free_stack(stack);
		}
		else
		{
			new = ft_lstnew(num);
			if (!new)
				free_stack(stack);
			if (!ft_lstadd_back(&stack->a_head, new))
				free_stack(stack);
			numbering(*stack, new);
		}
	}
	stack->a_bottom = new;
}

int	check_already_sorted(t_stack *stack)
{
	t_list	*tmp;

	tmp = stack->a_head;
	while (tmp->next)
	{
		if (tmp->idx > tmp->next->idx)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
