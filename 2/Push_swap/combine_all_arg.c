/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combine_all_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:43:49 by spark2            #+#    #+#             */
/*   Updated: 2023/08/22 19:23:52 by spark2           ###   ########.fr       */
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
		if (!is_only_space(argv[i], ' ')) //argv가 공백으로만 구성되어 있으면 에러
		{
			free(res);
			exit(1);
		}
		res = ft_strjoin(tmp, argv[i]); //인자를 공백과 함께 res에 붙이기
		free(tmp);
	}
	return (res);
}
