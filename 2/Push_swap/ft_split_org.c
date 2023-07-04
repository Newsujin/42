/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_org.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 19:23:49 by spark2            #+#    #+#             */
/*   Updated: 2023/07/04 23:27:55 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_free(char **ptr, int i)
{
	while (i >= 0)
		free(ptr[i--]);
	free(ptr);
	return (0);
}

int	cnt_word(const char *s, char c)
{
	int	word;

	word = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			word++;
		while (*s && *s != c)
			s++;
	}
	return (word);
}

char	*ft_word_dup(char const *s, int idx, char c)
{
	int		i;
	char	*dst;

	i = 0;
	printf("s[i+idx]============= %c\n", s[i+idx]);
	while (s[i + idx] && s[i + idx] != c)
		i++;
	dst = malloc(sizeof(char) * (i + 1));
	if (!dst)
		return (0);
	i = 0;
	while (s[i + idx] && s[i + idx] != c)
	{
		printf("src[iiiiii] = %c\n", s[i + idx]);
		dst[i] = s[i + idx];
		i++;
	}
	dst[i] = 0;
	printf("%p ============ %p\n", &dst[i], &s[i + idx]);
	printf("dstttttttt = %s\n", dst);
	return (dst);
}

char	**ft_split_org(char const *s, char c)
{
	int		i;
	int		j;
	int		cnt;
	char	**ptr;

	i = 0;
	j = 0;
	cnt = ft_strlen(s);
	ptr = malloc(sizeof(char *) * (cnt_word(s, c) + 1));
	if (!ptr)
		return (0);
	printf("%s\n", s);
	while (s[i] != 0)
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			printf("s[i] = %c\n", s[i]);
			ptr[j] = ft_word_dup(s, i, c);
			printf("i = %d, ptr[%d] = %s\n",i, j, ptr[j]);
			if (!ptr[j++])
				return (ft_free(ptr, j - 2));
		}
		while (s[i] && s[i] != c)
			i++;
		if (cnt != i)
			i++;
	}
	ptr[j] = 0;
	return (ptr);
}