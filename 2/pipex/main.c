/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 19:12:18 by spark2            #+#    #+#             */
/*   Updated: 2023/09/12 21:25:16 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_arg	arg;

	//argc는 무조건 5개로 고정되어 있으니 에러 처리
	if (argc != 5)
	{
		perror("argument error");
		exit(1);
	}
	//infile 과 outfile을 open한다.
	arg.infile = open(argv[1], O_RDONLY);
	if (arg.infile == -1)
	{
		perror("Could not open infile");
		exit(1);
	}
	arg.outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (arg.outfile == -1)
	{
		perror("Outfile error");
		exit(1);
	}
	//환경변수에서 PATH를 찾아서 PATH= 이후의 글자를 ft_split 으로 : 로 나눠서 저장한다.
	arg.path = get_path_envp(envp);
	while (*arg.path)
	{
		printf("path: %s\n", *arg.path);
		arg.path++;
	}
	//command를 가져온 다음 실행가능한 PATH를 확인한다.
	arg.cmd_arg1 = ft_split(argv[2], ' ');
	arg.cmd_arg2 = ft_split(argv[3], ' ');
	if (arg.cmd_arg1 == NULL || arg.cmd_arg2 == NULL)
		perror("cmd missing error");
	arg.cmd1 = get_cmd_argv(arg.path, arg.cmd_arg1[0]);
	arg.cmd2 = get_cmd_argv(arg.path, arg.cmd_arg2[0]);
	if (arg.cmd1 == NULL || arg.cmd2 == NULL)
		perror("path or cmd error");
}

//에러 함수 처리