/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 19:12:37 by spark2            #+#    #+#             */
/*   Updated: 2023/09/30 22:36:06 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_cmd_arg
{
	char	**arr;
}	t_cmd_arg;

typedef struct s_cmd
{
	int			execfile;
	t_cmd_arg	*arg;
}	t_cmd;

typedef struct s_arg
{
	int		infile;
	int		outfile;
	char	**path;
	char	**path_plus_cmd;
	int		pipe_fd[2];
	pid_t	pid;
}	t_arg;

void	check_argc(int argc);
void	set_file(t_arg *arg, char **argv);
void	get_path_envp(t_arg *arg, char **envp);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
char	*get_cmd_path(char **path, char *cmd);
void	set_cmd(t_arg *arg, t_cmd *cmd, char **argv);
void	run_fork(t_arg *arg, t_cmd *cmd, char **envp);
void	run_free(t_arg *arg, t_cmd *cmd);
void	free_2d_array(char **str);
void	print_error(char *err_msg);
void	infile_to_pipe(t_arg *arg);
void	pipe_to_outfile(t_arg *arg);
void	parent_work(t_arg *arg);

#endif