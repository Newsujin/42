/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:18:19 by spark2            #+#    #+#             */
/*   Updated: 2023/08/01 20:16:41 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_path(t_game *game)
{
	int	i;

	i = -1;
	game->dfs_map = malloc(sizeof(char *) * (game->map_height + 1));
	if (!game->dfs_map)
		ft_error("malloc error\n");
	game->dfs_map[game->map_height] = NULL;
	while (++i < game->map_height)
	{
		game->dfs_map[i] = ft_strdup(game->map[i]);
		if (!game->dfs_map[i])
			ft_error("malloc error\n");
	}
	dfs(game, game->now_y, game->now_x);
	if (game->door_flag != 1 || game->collect_flag != 1)
	{
		free(game->dfs_map);
		ft_error("path error\n");
	}
	i = -1;
	while (game->dfs_map[++i])
		free(game->dfs_map[i]);
	free(game->dfs_map);
}

void	dfs(t_game *game, int y, int x)
{
	if (game->c_cnt == 0)
		game->collect_flag = 1;
	if (game->dfs_map[y][x] == '1' || x < 0 || y < 0 || \
		x > game->map_width - 1 || y > game->map_height - 1)
		return ;
	if (game->dfs_map[y][x] == 'C')
		game->c_cnt--;
	if (game->dfs_map[y][x] == 'E')
		game->door_flag = 1;
	game->dfs_map[y][x] = '1';
	dfs(game, y - 1, x);
	dfs(game, y + 1, x);
	dfs(game, y, x - 1);
	dfs(game, y, x + 1);
}
