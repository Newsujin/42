/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 22:08:49 by spark2            #+#    #+#             */
/*   Updated: 2023/08/24 22:37:46 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	char	*res;
	char	**res_split;
	t_stack	stack;

	if (argc < 2)
		return (1);
	res = combine_all_arg(argc, argv);
	res_split = ft_split(res, ' ', &argc);
	free(res);
	ft_memset(&stack, 0, sizeof(t_stack));
	setting(&stack, argc, res_split);
	fd = open("res.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		printf("%s", line);
		free(line);
	}
	// atexit(leak_check);
	return (0);
}
