/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:47:25 by spark2            #+#    #+#             */
/*   Updated: 2023/07/31 20:07:40 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_to_put_image(t_game *game, int i, int j) //각 기호에 맞는 이미지 삽입
{
	if (game->map[i][j] == '1')
		mlx_put_image_to_window_tree(game);
	else if (game->map[i][j] == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->grass, \
			game->x, game->y);
	else if (game->map[i][j] == 'P')
		mlx_put_image_to_window_player(game, i, j);
	else if (game->map[i][j] == 'C')
		mlx_put_image_to_window_chest(game);
	else if (game->map[i][j] == 'E')
		mlx_put_image_to_window_door(game);
	else
		ft_error("wrong word in map error\n");
}

void	mlx_put_image_to_window_tree(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->grass, \
		game->x, game->y);
	mlx_put_image_to_window(game->mlx, game->win, game->tree, \
		game->x, game->y);
}

void	mlx_put_image_to_window_player(t_game *game, int i, int j)
{
	mlx_put_image_to_window(game->mlx, game->win, game->grass, \
			game->x, game->y);
	mlx_put_image_to_window(game->mlx, game->win, game->char_down, \
		game->x, game->y);
	game->now_x = j;
	game->now_y = i;
}

void	mlx_put_image_to_window_chest(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->grass, \
		game->x, game->y);
	mlx_put_image_to_window(game->mlx, game->win, game->chest, \
		game->x, game->y);
	game->items++;
}

void	mlx_put_image_to_window_door(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->grass, \
		game->x, game->y);
	mlx_put_image_to_window(game->mlx, game->win, game->door, \
		game->x, game->y);
}
