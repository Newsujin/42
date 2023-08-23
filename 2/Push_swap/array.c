/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 19:23:49 by spark2            #+#    #+#             */
/*   Updated: 2023/08/23 21:30:16 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*combine_all_arg(int argc, char **argv)
{
	int		i;
	char	*tmp;
	char	*res;

	i = 0;
	res = ft_strdup("");
	while (++i < argc)
	{
		tmp = res;
		if (!is_only_space(argv[i], ' '))
		{
			free(res);
			exit(1);
		}
		res = ft_strjoin(tmp, argv[i]);
		free(tmp);
	}
	return (res);
}

/* 인자를 공백 기준으로 split */
char	**ft_split(char const *s, char c, int *argc)
{
	int		i;
	int		j;
	int		cnt;
	char	**ptr;

	i = 0;
	j = 0;
	cnt = ft_strlen(s);
	*argc = cnt_word(s, c);
	ptr = malloc(sizeof(char *) * (*argc + 1));
	if (!ptr)
		return (0); //0 반환하면 exit 에러 처리
	while (s[i] != 0)
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			ptr[j] = ft_word_dup(s, i, c);
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
	while (s[i + idx] && s[i + idx] != c)
		i++;
	dst = malloc(sizeof(char) * (i + 1));
	if (!dst)
		return (0);
	i = 0;
	while (s[i + idx] && s[i + idx] != c)
	{
		dst[i] = s[i + idx];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

void	*ft_free(char **ptr, int i)
{
	while (i >= 0)
		free(ptr[i--]);
	free(ptr);
	return (0);
}