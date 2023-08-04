/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 21:04:48 by spark2            #+#    #+#             */
/*   Updated: 2023/08/01 20:47:16 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define KEY_ESC		53
# define KEY_PRESS		2
# define KEY_EXIT		17

# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./mlx/mlx.h"
# include "get_next_line.h"

typedef struct s_game {
	char	**map;
	char	**dfs_map;
	void	*mlx;
	void	*win;
	int		map_width;
	int		map_height;
	int		img_width;
	int		img_height;
	void	*duck;
	void	*tree;
	void	*grass;
	void	*bug;
	void	*door;
	void	*opened_door;
	int		p_cnt;
	int		c_cnt;
	int		e_cnt;
	int		now_x;
	int		now_y;
	int		x;
	int		y;
	int		items;
	int		collect_flag;
	int		door_flag;
	int		door_locate[2];
	int		walk;
}	t_game;

int		check_ac_av_fd(int ac, char *av);
void	check_p_e_c(t_game *game);
void	check_rectangle(t_game *game);

void	map_init(int fd, t_game *game);

void	set_mlx(t_game *game);
void	put_image(t_game *game);
void	check_map_to_put_image(t_game *game, int i, int j);
void	check_wall(t_game *game);
void	mlx_put_image_to_window_grass(t_game *game);
void	mlx_put_image_to_window_tree(t_game *game);
void	mlx_put_image_to_window_duck(t_game *game, int i, int j);
void	mlx_put_image_to_window_bug(t_game *game);
void	mlx_put_image_to_window_door(t_game *game);

void	check_path(t_game *game);
void	dfs(t_game *game, int y, int x);

int		press_key(int keycode, t_game *game);
void	move_player(t_game *game, int x, int y);
int		finish_game(t_game *game);

void	*ft_memset(void *arr, int value, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	**ft_split(char const *s, char c);
void	ft_putnbr_sub(int walk);
void	ft_putnbr(int n);
void	ft_error(char *s);

#endif