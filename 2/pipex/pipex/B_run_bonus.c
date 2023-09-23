/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B_run_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 20:33:01 by spark2            #+#    #+#             */
/*   Updated: 2023/09/23 20:55:18 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

/* pipe create / fork / parent, child work */
void	run_fork(t_arg  *arg, t_cmd *cmd, int argc, char **envp)
{
	int		i;

	i = -1;
	while (++i < argc - 3)
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
			else if (i != argc - 4)
				pipe_to_pipe(arg);
			else
				pipe_to_outfile(arg);
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
	close(arg->pipe_fd[0]);
	dup2(arg->infile, STDIN_FILENO);
	dup2(arg->pipe_fd[1], STDOUT_FILENO);
	close(arg->infile);
	close(arg->pipe_fd[1]);
}

/* STDOUT: outfile, execve */
void	pipe_to_pipe(t_arg *arg)
{
	dup2(arg->pipe_fd[1], STDOUT_FILENO);
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
