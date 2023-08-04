/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:19:27 by spark2            #+#    #+#             */
/*   Updated: 2023/08/01 20:46:24 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	press_key(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		finish_game(game);
	else if (keycode == KEY_W)
		move_player(game, game->now_x, game->now_y - 1);
	else if (keycode == KEY_A)
		move_player(game, game->now_x - 1, game->now_y);
	else if (keycode == KEY_S)
		move_player(game, game->now_x, game->now_y + 1);
	else if (keycode == KEY_D)
		move_player(game, game->now_x + 1, game->now_y);
	return (0);
}

int	finish_game(t_game *game)
{
	int	i;

	i = -1;
	while (game->map[++i])
		free(game->map[i]);
	free(game->map);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

void	move_player(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		return ;
	if (game->map[y][x] == 'E' && !game->items)
		finish_game(game);
	if (game->map[y][x] == 'C')
	{
		game->items--;
		game->map[y][x] = 0;
		mlx_put_image_to_window(game->mlx, game->win, game->grass, \
			x * 64, y * 64);
		if (!game->items)
			mlx_put_image_to_window(game->mlx, game->win, game->opened_door, \
				game->door_locate[1] * 64, game->door_locate[0] * 64);
	}
	mlx_put_image_to_window(game->mlx, game->win, game->grass, \
		game->now_x * 64, game->now_y * 64);
	if (game->map[game->now_y][game->now_x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->door,
			game->now_x * 64, game->now_y * 64);
	game->walk++;
	mlx_put_image_to_window(game->mlx, game->win, game->duck, \
		x * 64, y * 64);
	ft_putnbr_sub(game->walk);
	game->now_x = x;
	game->now_y = y;
}
