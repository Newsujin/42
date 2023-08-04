/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:47:25 by spark2            #+#    #+#             */
/*   Updated: 2023/08/01 20:39:47 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_put_image_to_window_grass(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->grass, \
		game->x, game->y);
}

void	mlx_put_image_to_window_tree(t_game *game)
{
	mlx_put_image_to_window_grass(game);
	mlx_put_image_to_window(game->mlx, game->win, game->tree, \
		game->x, game->y);
}

void	mlx_put_image_to_window_duck(t_game *game, int i, int j)
{
	mlx_put_image_to_window_grass(game);
	mlx_put_image_to_window(game->mlx, game->win, game->duck, \
		game->x, game->y);
	game->now_x = j;
	game->now_y = i;
}

void	mlx_put_image_to_window_bug(t_game *game)
{
	mlx_put_image_to_window_grass(game);
	mlx_put_image_to_window(game->mlx, game->win, game->bug, \
		game->x, game->y);
	game->items++;
}

void	mlx_put_image_to_window_door(t_game *game)
{
	mlx_put_image_to_window_grass(game);
	mlx_put_image_to_window(game->mlx, game->win, game->door, \
		game->x, game->y);
}
