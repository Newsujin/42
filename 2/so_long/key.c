/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:19:27 by spark2            #+#    #+#             */
/*   Updated: 2023/08/01 14:22:35 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	press_key(int keycode, t_game *game) //key에 따라 플레이어 이동
{
	if (keycode == KEY_ESC)
		finish_game(game);
	else if (keycode == KEY_W) //상
		move_player(game, game->now_x, game->now_y - 1);
	else if (keycode == KEY_A) //좌
		move_player(game, game->now_x - 1, game->now_y);
	else if (keycode == KEY_S) //하
		move_player(game, game->now_x, game->now_y + 1);
	else if (keycode == KEY_D) //우
		move_player(game, game->now_x + 1, game->now_y);
	//굳이 return 0?
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
			x * 64, y * 64); //땅 이미지 넣기
	}
	if (game->map[game->now_y][game->now_x] == 'E')
		mlx_put_image_to_window_door(game);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->grass,\
			game->now_x * 64, game->now_y * 64); //이전 장소에 풀 이미지 출력
	game->walk++;
	mlx_put_image_to_window(game->mlx, game->win, game->char_down, \
		x * 64, y * 64); //이동하려는 곳에 플레이어 이미지 출력
	ft_putnbr(game->walk);
	write(1, "\n", 1);
	game->now_x = x;
	game->now_y = y;
}