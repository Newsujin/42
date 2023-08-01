/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 21:04:48 by spark2            #+#    #+#             */
/*   Updated: 2023/08/01 14:24:53 by spark2           ###   ########.fr       */
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

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./mlx/mlx.h"
# include "get_next_line.h"

typedef struct s_game {
	char	**map;		//map 정보가 담길 2차원 배열들
	void	*mlx;		//mlx_init()의 리턴값이 담길 주소 포인터
	void	*win;		//mlx_new_window()의 리턴값이 담길 주소 포인터
	int		map_width;	//ber파일의 인자값 갯수
	int		map_height;	//ber파일의 인자값 갯수
	int		img_width;	//mlx_xpm_file_to_image의 3,4번째 인자값으로 사용할 이미지의 크기, 따로 설정하지 않아도 사진 크기에 맞게 조절됨 (주의, xpm으로 변환할 png파일들은 크기가 모두 같아야 함.)
	int		img_height;
	int		p_cnt; //Player의 갯수
	int		c_cnt; //Collect의 갯수
	int		e_cnt; //Exit의 갯수
	void	*char_up;
	void	*char_down;
	void	*char_left;
	void	*char_right;
	void	*tree;
	void	*grass;
	void	*chest;
	void	*door;
	int		now_x;		//캐릭터의 현재 위치
	int		now_y;		//캐릭터의 현재 위치
	int		x;			//캐릭터의 다음 위치
	int		y;			//캐릭터의 다음 위치
	int		items;		//캐릭터가 이동하며 아이템을 획득할 경우 하나씩 줄어들 아이템의 갯수 (0이 되고 E로 탈출해야 게임 종료)
	char	**dfs_map;	//dfs를 위한 map 복제
	int		collected;	//수집된 수집품 갯수
	int		door_flag;	//탈출할 수 있으면 1
	int		collect_flag; //수집품을 다 모으면 1
	int		walk;		//걸음 수
}	t_game;

//valid map check
void	check_ac_av(int ac, char *av);
void	check_p_e_c(t_game *game);
void	check_rectangle(t_game *game);

//split
char	**ft_split(char const *s, char c);
void	*ft_memset(void *arr, int value, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);

//util
size_t	ft_strlen(const char *str);

//set_mlx_img
void	set_mlx(t_game *game);
void	put_image(t_game *game);
void	check_map_to_put_image(t_game *game, int i, int j);
void	check_wall(t_game *game);
void	mlx_put_image_to_window_tree(t_game *game);
void	mlx_put_image_to_window_player(t_game *game, int i, int j);
void	mlx_put_image_to_window_chest(t_game *game);
void	mlx_put_image_to_window_door(t_game *game);

//path
void	check_path(t_game *game);
void	dfs(t_game *game, int y, int x);

//key
int		press_key(int keycode, t_game *game);
void	move_player(t_game *game, int x, int y);
int		finish_game(t_game *game);

//putnbr
void	ft_putnbr(int n);

//error
void	ft_error(char *s);

#endif