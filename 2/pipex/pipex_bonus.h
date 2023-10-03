/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 19:12:37 by spark2            #+#    #+#             */
/*   Updated: 2023/10/03 17:32:55 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include <fcntl.h>

typedef struct s_cmd_arg
{
	char	**arr;
}	t_cmd_arg;

typedef struct s_cmd
{
	t_cmd_arg	*arg;
}	t_cmd;

typedef struct s_arg
{
	int		infile;
	int		outfile;
	char	**path;
	int		pipe_fd[2];
	pid_t	pid;
	int		here_flag;
}	t_arg;

void	check_argc(int argc);
void	set_file(t_arg *arg, int argc, char **argv);

void	run_heredoc(t_arg *arg, char *limiter);

void	get_path_envp(t_arg *arg, char **envp);
char	*get_cmd_path(char **path, char *cmd);

void	set_cmd(t_arg *arg, t_cmd *cmd, int argc, char **argv);

void	run_fork(t_arg *arg, t_cmd *cmd, int argc, char **envp);

void	run_free(t_arg *arg, t_cmd *cmd, int argc);
void	free_2d_array(char **str);
void	print_error(char *err_msg);

void	infile_to_pipe(t_arg *arg);
void	pipe_to_pipe(t_arg *arg);
void	pipe_to_outfile(t_arg *arg);
void	parent_work(t_arg *arg);

void	wait_process(void);

#endif