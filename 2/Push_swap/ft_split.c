/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 19:23:49 by spark2            #+#    #+#             */
/*   Updated: 2023/06/30 21:15:27 by spark2           ###   ########.fr       */
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

int	cnt_word(const char **s, int **argc)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (*(s[i]))
	{
		while (*(s[i]) && *(s[i]) == ' ')
			s++;
		if (*s)
			word++;
		while (*s && *s != ' ')
			s++;
	}
	if (word > 1)
		**argc += word - 1;
	return (word);
}

char	*ft_word_dup(const char *src)
{
	int		i;
	char	*dst;

	i = 0;
	while (src[i] && src[i] != ' ')
		i++;
	dst = malloc(sizeof(char) * (i + 1));
	if (!dst)
		return (0);
	i = 0;
	while (src[i] && src[i] != ' ')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

char	**ft_split(char const **s, int *argc)
{
	int		i;
	int		j;
	char	**ptr;

	i = 0;
	j = 0;
	ptr = malloc(sizeof(char *) * (cnt_word(s, &argc) + 1));
	if (!ptr)
		return (0);
	while (s[i])
	{
		while (s[i] && s[i] == ' ')
			i++;
		if (s[i])
		{
			ptr[j] = ft_word_dup(&s[i]);
			if (!ptr[j++])
				return (ft_free(ptr, j - 2));
		}
		while (s[i] && s[i] != ' ')
			i++;
	}
	ptr[j] = 0;
	return (ptr);
}

// int	main(int argc, char **argv)
// {
// 	char	**res;
// 	int		i;
// 	int		argc_org;

// 	i = 0;
// 	argc_org = argc;
// 	while (++i < argc_org)
// 	{
// 		res = ft_split(argv[i], &argc);
// 		printf("%d\n", argc);
// 		printf("%s\n", res[i - 1]);
// 	}
// 	i = -1;
// 	// while (++i < argc)
// 	// 	printf("%s\n", res[i]);
// }