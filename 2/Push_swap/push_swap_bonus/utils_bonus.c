/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 16:31:28 by spark2            #+#    #+#             */
/*   Updated: 2023/08/24 22:23:14 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_only_space(const char *s, int c)
{
	while (*s)
	{
		if (*s != (char)c)
			return (1);
		s++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return ((int)(sign * res));
}

char	*ft_strdup(const char *src)
{
	int		i;
	char	*dst;

	i = 0;
	while (src[i])
		i++;
	dst = (char *)malloc(sizeof(char) * i + 1);
	if (!dst)
		return (0);
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		i;
	char	*str;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	i = 0;
	while (*s1)
	{
		str[i] = *s1++;
		i++;
	}
	str[i] = ' ';
	i++;
	while (*s2)
	{
		str[i] = *s2++;
		i++;
	}
	str[i] = 0;
	return (str);
}
