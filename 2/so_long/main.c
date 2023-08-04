/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 22:04:37 by spark2            #+#    #+#             */
/*   Updated: 2023/08/01 20:56:49 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *s)
{
	write(1, s, ft_strlen(s));
	exit(0);
}

void	map_init(int fd, t_game *game)
{
	char	*line;
	char	*all_line;
	char	*temp;

	all_line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		game->map_height++;
		temp = all_line;
		all_line = ft_strjoin(all_line, line);
		if (temp)
			free(temp);
		if (!all_line)
			free(all_line);
		free(line);
		line = NULL;
	}
	game->map = ft_split(all_line, '\n');
	if (!game->map)
		ft_error("malloc error");
	free(all_line);
}

int	main(int ac, char **av)
{
	int		fd;
	t_game	game;

	fd = check_ac_av_fd(ac, av[1]);
	ft_memset(&game, 0, sizeof(t_game));
	map_init(fd, &game);
	check_p_e_c(&game);
	check_rectangle(&game);
	set_mlx(&game);
	check_path(&game);
	mlx_hook(game.win, KEY_PRESS, 0, &press_key, &game);
	mlx_hook(game.win, 17, 0, &finish_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
