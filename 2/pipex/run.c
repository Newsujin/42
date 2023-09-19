/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 20:33:01 by spark2            #+#    #+#             */
/*   Updated: 2023/09/19 22:46:29 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	run_fork(t_arg *arg, char **envp, int i)
{
	// 파이프를 만든 다음 자식 프로세스를 만든다
	// if (i > 2)
	// {
	// 	close(arg->pipe_fd[0]);
	// 	close(arg->pipe_fd[1]);
	// }
	// if (i != 1)
	// {
		if (pipe(arg->pipe_fd) < 0)
		print_error("pipe error");
	// }
	//printf("%d %d", arg->pipe_fd[0], arg->pipe_fd[1]);
	char a = arg->pipe_fd[0] + '0';
	char b = arg->pipe_fd[1] + '0';

	write(1,  &a, 1);
	write(1, &b , 1);
	//if (i < 2)
	arg->pid = fork();
	// pid 값을 이용하여 에러와 자식 프로세스와 부모 프로세스를 분기한다
	if (arg->pid == -1)
		print_error("fork error");
	//자식
	else if (arg->pid == 0)
	{
		// 표준 입력을 infile로 바꾸고, 표준 출력을 pipe로 바꾼 다음 명령어를 실행한다
		if (i == 0)
		{
			printf("here2\n");
			close(arg->pipe_fd[0]);
			//dup2(arg->infile, STDIN_FILENO);
			dup2(arg->pipe_fd[1], STDOUT_FILENO);
			//close(arg->infile);
			close(arg->pipe_fd[1]);
			execve(arg->cmd1_path, arg->cmd1, envp);
		}
		else
		{
			char c = arg->pipe_fd[0] + '0';
			char d = arg->pipe_fd[1] + '0';

			write(1,  &c, 1);
			write(1, &d , 1);
			printf("here\n");
			close(arg->pipe_fd[1]);
			//dup2(arg->pipe_fd[0], STDIN_FILENO);
			//dup2(arg->outfile, STDOUT_FILENO);
			//close(arg->pipe_fd[0]);
			//close(arg->outfile);
			execve(arg->cmd2_path, arg->cmd2, envp);
		}
	}
	//부모
	else
	{
		char c = arg->pipe_fd[0] + '0';
		char d = arg->pipe_fd[1] + '0';

		write(1,  &c, 1);
		write(1, &d , 1);
		// 표준 입력을 pipe로 바꾸고, 표준 출력을 outfile 로 바꾼
		close(arg->pipe_fd[1]);
		dup2(arg->pipe_fd[0], STDIN_FILENO);
		// char qwe = arg->pipe_fd[1] + '0';

		// write(1, "here : !!!\n" , 11);
		// write(1,  &qwe, 1);
		// write(1, "\n" , 1);
		// dup2(arg->outfile, STDOUT_FILENO);
		close(arg->pipe_fd[0]);
		char qwe = arg->pipe_fd[0] + '0';

		write(1, "here : !!!\n" , 11);
		write(1,  &qwe, 1);
		write(1, "\n" , 1);
		//close(arg->infile);
		//close(arg->outfile);
		// 자식 프로세스가 끝나기를 기다려서 pipe에 값을 받아온 다음 명령어를 실행한다
		waitpid(arg->pid, NULL, 0);
		// execve(arg->cmd2_path, arg->cmd2, envp);
	}
	// close(arg->pipe_fd[0]);
	// close(arg->pipe_fd[1]);
}
