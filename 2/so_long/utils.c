/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:46:45 by spark2            #+#    #+#             */
/*   Updated: 2023/08/01 20:46:41 by spark2           ###   ########.fr       */
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

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst2;
	unsigned char	*src2;

	dst2 = (unsigned char *)dst;
	src2 = (unsigned char *)src;
	while (!dst2 && !src2)
		return (0);
	while (n--)
		*dst2++ = *src2++;
	return (dst);
}

void	ft_putnbr_sub(int walk)
{
	ft_putnbr(walk);
	write(1, "\n", 1);
}

void	ft_putnbr(int n)
{
	if (!n)
	{
		write(1, "0", 1);
		return ;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		n %= 10;
	}
	n += '0';
	write(1, &n, 1);
}
