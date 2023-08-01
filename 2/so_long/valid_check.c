/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 13:55:01 by spark2            #+#    #+#             */
/*   Updated: 2023/07/31 20:12:08 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_ac_av(int ac, char *av) //ac 1개인지 체크, .ber 체크
{
	int	i;

	i = 0;
	if (ac != 2)
	{
		write(1, "ac error\n", 9);
		exit(0);
	}
	while (av[i])
		i++;
	if (!(av[i - 1] == 'r' && av[i - 2] == 'e' && av[i - 3] == 'b'
			&& av[i - 4] == '.'))
	{
		write(1, ".ber error\n", 11);
		exit(0);
	}
}

void	check_p_e_c(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'P')
				game->p_cnt++;
			else if (game->map[i][j] == 'E')
				game->e_cnt++;
			else if (game->map[i][j] == 'C')
				game->c_cnt++;
		}
	}
	if (game->p_cnt != 1 || game->e_cnt != 1 || game->c_cnt < 1)
	{
		write(1, "P E C error\n", 12);
		exit(0);
	}
}

void	check_rectangle(t_game *game)
{
	int	i;

	i = 0;
	game->map_width = (int)ft_strlen(game->map[i]);
	if (game->map_width == 0)
	{
		write(1, "rectangle error\n", 16);
		exit(0);
	}
	while (game->map[++i])
	{
		if (game->map_width != (int)ft_strlen(game->map[i]))
		{
			write(1, "rectangle error\n", 16);
			exit(0);
		}
	}
}
