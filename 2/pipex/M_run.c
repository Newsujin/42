/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   M_run.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 20:33:01 by spark2            #+#    #+#             */
/*   Updated: 2023/09/30 16:49:11 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* pipe create / fork / parent, child work */
void	run_fork(t_arg *arg, t_cmd *cmd, char **envp)
{
	int		i;

	i = -1;
	while (++i < 2)
	{
		if (pipe(arg->pipe_fd) < 0)
			print_error("pipe error");
		arg->pid = fork();
		if (arg->pid == -1)
			print_error("fork error");
		else if (arg->pid == 0)
		{
			if (i == 0)
				infile_to_pipe(arg);
			else
				pipe_to_outfile(arg);
			// if (!arg->path_plus_cmd[i])
			// 	print_error("exec error(권한X or 틀린 명령어)");
			execve(arg->path_plus_cmd[i], cmd->arg[i].arr, envp);
		}
		else
			parent_work(arg);
	}
	waitpid(-1, NULL, 0);
	waitpid(-1, NULL, 0);
}

/* STDIN: infile, STDOUT: pipe, execve */
void	infile_to_pipe(t_arg *arg)
{
	if (arg->infile < 0)
		print_error("infile error");
	close(arg->pipe_fd[0]);
	dup2(arg->infile, STDIN_FILENO);
	dup2(arg->pipe_fd[1], STDOUT_FILENO);
	close(arg->infile);
	close(arg->pipe_fd[1]);
}

/* STDOUT: outfile, execve */
void	pipe_to_outfile(t_arg *arg)
{
	close(arg->pipe_fd[1]);
	dup2(arg->outfile, STDOUT_FILENO);
	close(arg->outfile);
}

/* STDIN: pipe */
void	parent_work(t_arg *arg)
{
	dup2(arg->pipe_fd[0], STDIN_FILENO);
	close(arg->pipe_fd[1]);
	close(arg->pipe_fd[0]);
}
