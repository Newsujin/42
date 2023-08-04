/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:59:09 by spark2            #+#    #+#             */
/*   Updated: 2023/08/01 20:39:13 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_mlx(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map_width * 64, \
		game->map_height * 64, "my_mlx");
	game->duck = mlx_xpm_file_to_image(game->mlx, "./textures/duck.xpm", \
		&game->img_width, &game->img_height);
	game->tree = mlx_xpm_file_to_image(game->mlx, "./textures/tree.xpm", \
		&game->img_width, &game->img_height);
	game->grass = mlx_xpm_file_to_image(game->mlx, "./textures/grass.xpm", \
		&game->img_width, &game->img_height);
	game->bug = mlx_xpm_file_to_image(game->mlx, "./textures/bug.xpm", \
		&game->img_width, &game->img_height);
	game->door = mlx_xpm_file_to_image(game->mlx, "./textures/door.xpm", \
		&game->img_width, &game->img_height);
	game->opened_door = mlx_xpm_file_to_image(game->mlx, \
		"./textures/opened_door.xpm", &game->img_width, &game->img_height);
	if (!game->duck || !game->tree || !game->grass || \
		!game->bug || !game->door)
		ft_error("mlx error");
	put_image(game);
}

void	put_image(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	game->y = 0;
	while (game->map[++i])
	{
		j = -1;
		game->x = 0;
		while (game->map[i][++j])
		{
			check_map_to_put_image(game, i, j);
			check_wall(game);
			game->x += 64;
		}
		game->y += 64;
	}
}

void	check_wall(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->map_width)
	{
		if (game->map[0][i] != '1')
			ft_error("wall error\n");
		if ((game->map[game->map_height - 1][i]) != '1')
			ft_error("wall error\n");
	}
	i = -1;
	while (++i < game->map_height)
	{
		if (game->map[i][0] != '1')
			ft_error("wall error\n");
		if (game->map[i][game->map_width - 1] != '1')
			ft_error("wall error\n");
	}
}
