/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:37:37 by spark2            #+#    #+#             */
/*   Updated: 2024/02/15 10:51:29 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void	error(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	exit(1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2 || check_argv(argv[1]))
		error("Error\narg\n");
	parsing(&game, argv[1]);
	executing(&game);
}
