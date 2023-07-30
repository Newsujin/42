/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 21:04:48 by spark2            #+#    #+#             */
/*   Updated: 2023/07/28 21:11:32 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define KEY_ESC		53
# define KEY_PRESS		2
# define KEY_RELEASE 	3
# define KEY_EXIT		17

# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

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
	char	**dfs_map;	//map 정보가 담길 2차원 배열들
	int		collected;	//수집된 수집품 갯수
	int		door_flag;	//탈출할 수 있으면 1
	int		collect_flag; //수집품을 다 모으면 1
	int		walk;		//걸음 수
}	t_game;

typedef struct s_data {
	char	**ber_arr;	//map 정보가 담길 2차원 배열들
	void	*mlx;		//mlx_init()의 리턴값이 담길 주소 포인터
	void	*win;		//mlx_new_window()의 리턴값이 담길 주소 포인터
	void	*grass;		//ber_arr[][]의 값이 '0'일 경우 땅 이미지를 넣을 포인터
	void	*wall;		//"" '1'일 경우 벽 이미지를 넣을 포인터
	void	*player;	// "" 'P'일 경우 캐릭터 이미지를 넣을 포인터
	void	*chest;		// "" 'C'일 경우 아이템 이미지를 넣을 포인터
	void	*door;		// "" 'E'일 경우 문 이미지를 넣을 포인터
	char	*map;
	int		items;		//캐릭터가 이동하며 아이템을 획득할 경우 하나씩 줄어들 아이템의 갯수 (0이 되고 E로 탈출해야 게임 종료)
	int		walk;		//걸음수를 terminal에 출력하기 위한 걸음수 체크 변수
	int		now_x;		//캐릭터의 현재 위치
	int		now_y;		//캐릭터의 현재 위치
	int		x;			//캐릭터의 다음 위치
	int		y;			//캐릭터의 다음 위치
	int		map_width;	//ber파일의 인자값 갯수
	int		map_height;	//ber파일의 인자값 갯수
	int		img_width;	//mlx_xpm_file_to_image의 3,4번째 인자값으로 사용할 이미지의 크기, 따로 설정하지 않아도 사진 크기에 맞게 조절됨 (주의, xpm으로 변환할 png파일들은 크기가 모두 같아야 함.)
	int		img_height;	//""
}				t_data;

typedef struct s_dfs {
	int	items;			//dfs에서 검사할 유효한 아이템
	int	door;			//dfs에서 검사할 유효한 문
	int	**arr;			//dfs에서 사용할 ber_arr과 똑같은 이중배열 포인터
}				t_dfs;

char	**ft_split(char const *s, char c);
void	*ft_memset(void *arr, int value, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);

#endif