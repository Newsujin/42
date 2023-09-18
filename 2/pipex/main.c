/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 19:12:18 by spark2            #+#    #+#             */
/*   Updated: 2023/09/18 20:46:01 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// void	leaks()
// {
// 	system("leaks pipex");
// }

//envp?
//perror?
int	main(int argc, char **argv, char **envp)
{
	t_arg	arg;
	// atexit(leaks);

	check_argc(argc);
	ft_memset(&arg, 0, sizeof(arg));
	check_file(&arg, argv);
	arg.path = get_path_envp(envp);
	//argv[2], argv[3]의 command를 각각 띄어쓰기를 기준으로 split
	arg.cmd1 = ft_split(argv[2], ' ');
	arg.cmd2 = ft_split(argv[3], ' ');
	if (arg.cmd1 == NULL || arg.cmd2 == NULL)
		perror("cmd missing error");
	arg.cmd1_path = get_cmd_argv(arg.path, arg.cmd1[0]);
	arg.cmd2_path = get_cmd_argv(arg.path, arg.cmd2[0]);
	if (arg.cmd1_path == NULL || arg.cmd2_path == NULL)
		perror("path or cmd error");
	printf("%s, %s \n", arg.cmd1_path, arg.cmd2_path);
	free_2d_array(arg.path);
	run_fork(&arg, envp);

	//free
	free(arg.cmd1_path);
	free(arg.cmd2_path);
	free_2d_array(arg.cmd1);
	free_2d_array(arg.cmd2);
}

//에러 함수 처리