/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 22:04:37 by spark2            #+#    #+#             */
/*   Updated: 2023/08/01 14:20:27 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx/mlx.h"
#include "so_long.h"
#include "get_next_line.h"

void	ft_error(char *s)
{
	write(1, s, ft_strlen(s));
	exit(0);
}

/* map을 파싱하여 game에 이중 배열로 저장 */
void	map_init(char *av, t_game *game)
{
	int		fd;
	char	*line;
	char	*all_line;
	char	*temp;

	all_line = NULL;
	fd = open(av, O_RDONLY);
	if (fd <= 0)
		ft_error("fd error\n");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		game->map_height++;
		temp = all_line;
		all_line = ft_strjoin(all_line, line); //strjoin 안에서 free 하면 깔끔해짐 (귀정)
		if (temp)
			free(temp);
		free(line);
		line = NULL;
	}
	game->map = ft_split(all_line, '\n');
	if (!game->map)
		ft_error("malloc error");
	free(all_line);
}

void	_leaks()
{
	system("leaks so_long");
}

int	main(int ac, char **av)
{
	t_game	game;

	check_ac_av(ac, av[1]);
	ft_memset(&game, 0, sizeof(t_game)); //game을 0으로 초기화
	map_init(av[1], &game); //map 파싱하여 game에 저장
	if (game.map == 0) //널가드
		ft_error("malloc error\n");
	check_p_e_c(&game);
	check_rectangle(&game);
	set_mlx(&game);
	//system("leaks so_long");
	atexit(_leaks);
	check_path(&game);
	mlx_hook(game.win, KEY_PRESS, 0, &press_key, &game);
	mlx_hook(game.win, 17, 0, &finish_game, &game);
	mlx_loop(game.mlx);
	int i = -1;
	while (game.map[++i])
		free(game.map[i]);
	free(game.map);
	return (0);
}