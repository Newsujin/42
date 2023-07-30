/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 22:04:37 by spark2            #+#    #+#             */
/*   Updated: 2023/07/30 18:09:28 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx/mlx.h"
#include "so_long.h"
#include "get_next_line.h"

void	error(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	exit(0);
}

int	check_ac_av(int ac, char *av) //ac 1개 체크, .ber 체크
{
	int	i;

	i = 0;
	if (ac != 2)
		return (0);
	while (av[i])
		i++;
	if (av[i - 1] == 'r' && av[i - 2] == 'e' && av[i - 3] == 'b'
		&& av[i - 4] == '.')
		return (1);
	return (0);
}

char	**map_gnl(char *av, t_game *game) //map을 파싱하여 game에 이중 배열로 저장
{
	int		fd;
	char	*line;
	char	*all_line;

	all_line = ft_strdup("");
	fd = open(av, O_RDONLY);
	if (fd <= 0)
		error("fd error!\n");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		game->map_height++;
		all_line = ft_strjoin(all_line, line);
		free(line);
		line = NULL;
	}
	return (ft_split(all_line, '\n'));
}

int	is_rectangle(int i, t_game *game)
{
	if (i == 0)
		game->map_width = (int)ft_strlen(game->map[i]);
	else
	{
		if (game->map_width != (int)ft_strlen(game->map[i]))
			return (0);
	}
	if (game->map_width == 0)
		return (0);
	return (1);
}

void	valid_check(t_game *game) //P, E, C 갯수 체크, 직사각형 체크
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
				game->p_cnt++;
			else if (game->map[i][j] == 'E')
				game->e_cnt++;
			else if (game->map[i][j] == 'C')
				game->c_cnt++;
			j++;
		}
		i++;
	}
	if (game->p_cnt != 1 || game->e_cnt != 1 || game->c_cnt < 1)
		error("p e c Error!\n");
	i = 0;
	while (game->map[i])
	{
		if (!is_rectangle(i, game))
			error("is not rectangle!\n");
		i++;
	}
}

void	check_map(t_game *game, int i, int j)
{
	if (game->map[i][j] == '1')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->grass, game->x, game->y);
		mlx_put_image_to_window(game->mlx, game->win, game->tree, game->x, game->y);
	}
	else if (game->map[i][j] == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->grass, game->x, game->y);
	else if (game->map[i][j] == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->grass, game->x, game->y);
		mlx_put_image_to_window(game->mlx, game->win, game->char_down, game->x, game->y);
		game->now_x = j;
		game->now_y = i;
	}
	else if (game->map[i][j] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->grass, game->x, game->y);
		mlx_put_image_to_window(game->mlx, game->win, game->chest, game->x, game->y);
		game->items++;
	}
	else if (game->map[i][j] == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->grass, game->x, game->y);
		mlx_put_image_to_window(game->mlx, game->win, game->door, game->x, game->y);
	}
	else
	{
		printf("Wrong Map! (unvalid word)\n");
		exit(0);
	}
}

void	check_wall(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->map_width)
	{
		if (game->map[0][i] != '1')
		{
			printf("Wall Error!\n");
			exit(0);
		}
		if ((game->map[game->map_height - 1][i]) != '1')
		{
			printf("Wall Error!\n");
			exit(0);
		}
	}
	i = -1;
	while (++i < game->map_height)
	{
		if (game->map[i][0] != '1')
		{
			printf("Wall Error!\n");
			exit(0);
		}
		if (game->map[i][game->map_width - 1] != '1')
		{
			printf("Wall Error!\n");
			exit(0);
		}
	}
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
			check_map(game, i, j);
			check_wall(game);
			game->x += 64;
			cnt++;
		}
		game->y += 64;
	}
}

void	set_mlx(t_game *game) //mlx 세팅
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map_width * 64, game->map_height * 64, "my_mlx");
	game->char_up = mlx_xpm_file_to_image(game->mlx, "./images/up.xpm", &game->img_width, &game->img_height);
	game->char_down = mlx_xpm_file_to_image(game->mlx, "./images/down.xpm", &game->img_width, &game->img_height);
	game->char_left = mlx_xpm_file_to_image(game->mlx, "./images/left.xpm", &game->img_width, &game->img_height);
	game->char_right = mlx_xpm_file_to_image(game->mlx, "./images/right.xpm", &game->img_width, &game->img_height);
	game->tree = mlx_xpm_file_to_image(game->mlx, "./images/tree.xpm", &game->img_width, &game->img_height);
	game->grass = mlx_xpm_file_to_image(game->mlx, "./images/grass.xpm", &game->img_width, &game->img_height);
	game->chest = mlx_xpm_file_to_image(game->mlx, "./images/chest.xpm", &game->img_width, &game->img_height);
	game->door = mlx_xpm_file_to_image(game->mlx, "./images/door.xpm", &game->img_width, &game->img_height);
	//절대 경로가 아니라면 널을 반환하기 때문에 예외 처리 하기!!!!
	put_image(game);
}

void	dfs(t_game *game, int y, int x)
{
	if (game->c_cnt == 0)
		game->collect_flag = 1;
	if (game->dfs_map[y][x] == '1' || x < 0 || y < 0 || x > game->map_width - 1 || y > game->map_height - 1)// || game->c_cnt == 0)
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

void	check_path(t_game *game)
{
	int	i;

	i = -1;

	game->dfs_map = malloc(sizeof(char *) * game->map_height + 1);
	game->dfs_map[game->map_height] = 0;

	while (++i < game->map_height)
	{


		printf("1111\n");


		// game->dfs_map[i] = malloc(sizeof(char) * game->map_width + 1);
		//if (!game->dfs_map[i]) //이중 free하기

		// game->dfs_map[game->map_width] = 0;


		printf("2222\n");

		printf("map: %s", game->map[0]);



		printf("333\n");

		game->dfs_map[i] = ft_strdup(game->map[i]);
		// ft_memcpy(game->dfs_map[i], game->map[i], game->map_width); //segmentation fault > invali_pathE


		printf("4444\n");
	}

	printf("before dfs\n");
	dfs(game, game->now_y, game->now_x);


	printf("after dfs\n");
	printf("game->total_collect_cnt : %d, game->door_flag : %d\n", game->c_cnt, game->door_flag);

	if (game->door_flag != 1 || game->collect_flag != 1)
	{
		printf("path Error!\n");
		free(game->dfs_map);
		exit(0);
	}
}

void	finish_game(t_game *game)
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
		mlx_put_image_to_window(game->mlx, game->win, game->grass, x * 64, y * 64); //땅 이미지 넣기
	}
	if (game->map[game->now_y][game->now_x] == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->grass, game->now_x * 64, game->now_y * 64); //땅 이미지 넣기
		mlx_put_image_to_window(game->mlx, game->win, game->door, game->now_x * 64, game->now_y * 64); //문 이미지 넣기
	}
	else
		mlx_put_image_to_window(game->mlx, game->win, game->grass, game->now_x * 64, game->now_y * 64); //이전 장소에 풀 이미지 출력
	game->walk++;
	mlx_put_image_to_window(game->mlx, game->win, game->char_down, x * 64, y * 64); //이동하려는 곳에 플레이어 이미지 출력
	printf("walk: %d\n", game->walk);
	game->now_x = x;
	game->now_y = y;
	printf("now_x: %d, now_y: %d\n", game->now_x, game->now_y);
}

int	act_key(int	keycode, t_game *game) //key에 따라 플레이어 이동
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
	//굳이 return 0?
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (check_ac_av(ac, av[1]) == 0)
		return (printf("check error\n"));
	ft_memset(&game, 0, sizeof(t_game)); //game을 0으로 초기화
	game.map = map_gnl(av[1], &game); //map 파싱하여 game에 저장
	if (game.map == 0) //널가드
		return (printf("open error\n"));
	valid_check(&game); //
	set_mlx(&game);
	printf("y: %d, x: %d\n", game.now_y, game.now_x);
	// system("leaks so_long");
	check_path(&game);
	mlx_hook(game.win, KEY_PRESS, 0, &act_key, &game);
	mlx_loop(game.mlx);
	return (0);
}