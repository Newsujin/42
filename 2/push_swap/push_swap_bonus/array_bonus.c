/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 22:18:04 by spark2            #+#    #+#             */
/*   Updated: 2023/08/28 13:10:21 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
			write(1, "Error\n", 6);
			free_array(res);
		}
		res = ft_strjoin(tmp, argv[i]);
		free(tmp);
	}
	return (res);
}

char	**ft_split(char *s, char c, int *argc)
{
	int		j;
	char	**ptr;

	j = 0;
	*argc = cnt_word(s, c);
	ptr = malloc(sizeof(char *) * (*argc + 1));
	if (!ptr)
		free_array(s);
	ptr = spliting(&j, c, s, ptr);
	ptr[j] = 0;
	return (ptr);
}

int	cnt_word(char *s, char c)
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

char	**spliting(int *j, char c, char *s, char **ptr)
{
	int		i;

	i = 0;
	while (s[i] != 0)
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			ptr[*j] = ft_word_dup(s, i, c);
			if (!ptr[(*j)++])
			{
				free_split(ptr, *j - 2);
				free_array(s);
			}
		}
		while (s[i] && s[i] != c)
			i++;
	}
	return (ptr);
}

char	*ft_word_dup(char *s, int idx, char c)
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
