/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:29:43 by spark2            #+#    #+#             */
/*   Updated: 2023/07/31 20:48:50 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
