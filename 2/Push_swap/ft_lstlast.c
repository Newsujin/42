/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:44:33 by spark2            #+#    #+#             */
/*   Updated: 2023/08/04 18:13:17 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstlast(t_list *lst, t_list *new)
{
	while (lst->next) //lst == 0은 lst 자체가 없는 걸 의미, 따라서 lst->next == 0 조건문으로 판별
	{
		if (lst->content == new->content) //리스트에 content 중복이 있는지 체크
			return (0);
		lst = lst->next;
	}
	if (lst->content == new->content)
		return (0);
	return (lst);
}