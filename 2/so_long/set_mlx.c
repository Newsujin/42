/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:59:09 by spark2            #+#    #+#             */
/*   Updated: 2023/07/31 22:50:40 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_mlx(t_game *game) //mlx 세팅
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map_width * 64, \
		game->map_height * 64, "my_mlx");
	game->char_up = mlx_xpm_file_to_image(game->mlx, "./images/up.xpm", \
		&game->img_width, &game->img_height);
	game->char_down = mlx_xpm_file_to_image(game->mlx, "./images/down.xpm", \
		&game->img_width, &game->img_height);
	game->char_left = mlx_xpm_file_to_image(game->mlx, "./images/left.xpm", \
		&game->img_width, &game->img_height);
	game->char_right = mlx_xpm_file_to_image(game->mlx, "./images/right.xpm", \
		&game->img_width, &game->img_height);
	game->tree = mlx_xpm_file_to_image(game->mlx, "./images/tree.xpm", \
		&game->img_width, &game->img_height);
	game->grass = mlx_xpm_file_to_image(game->mlx, "./images/grass.xpm", \
		&game->img_width, &game->img_height);
	game->chest = mlx_xpm_file_to_image(game->mlx, "./images/chest.xpm", \
		&game->img_width, &game->img_height);
	game->door = mlx_xpm_file_to_image(game->mlx, "./images/door.xpm", \
		&game->img_width, &game->img_height);
	//절대 경로가 아니라면 널을 반환하기 때문에 예외 처리 하기!!!!
	put_image(game);
}

void	put_image(t_game *game)
{
	int	i;
	int	j;
	int	cnt;

	i = -1;
	game->y = 0;
	cnt = 0;
	while (game->map[++i])
	{
		j = -1;
		game->x = 0;
		while (game->map[i][++j])
		{
			check_map_to_put_image(game, i, j);
			check_wall(game);
			game->x += 64;
			cnt++;
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