/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 13:55:01 by spark2            #+#    #+#             */
/*   Updated: 2023/08/01 20:39:41 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_ac_av_fd(int ac, char *av)
{
	int	i;
	int	fd;

	i = 0;
	if (ac != 2)
		ft_error("ac error\n");
	while (av[i])
		i++;
	if (!(av[i - 1] == 'r' && av[i - 2] == 'e' && av[i - 3] == 'b'
			&& av[i - 4] == '.'))
		ft_error(".ber error\n");
	fd = open(av, O_RDONLY);
	if (fd < 0)
		ft_error("fd error\n");
	return (fd);
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
		ft_error("P E C error\n");
}

void	check_rectangle(t_game *game)
{
	int	i;

	i = 0;
	game->map_width = (int)ft_strlen(game->map[i]);
	if (game->map_width == 0)
		ft_error("rectangle error\n");
	while (game->map[++i])
	{
		if (game->map_width != (int)ft_strlen(game->map[i]))
			ft_error("rectangle error\n");
	}
}

void	check_map_to_put_image(t_game *game, int i, int j)
{
	if (game->map[i][j] == '1')
		mlx_put_image_to_window_tree(game);
	else if (game->map[i][j] == '0')
		mlx_put_image_to_window_grass(game);
	else if (game->map[i][j] == 'P')
		mlx_put_image_to_window_duck(game, i, j);
	else if (game->map[i][j] == 'C')
		mlx_put_image_to_window_bug(game);
	else if (game->map[i][j] == 'E')
	{
		mlx_put_image_to_window_door(game);
		game->door_locate[0] = i;
		game->door_locate[1] = j;
	}
	else
		ft_error("wrong word in map error\n");
}
