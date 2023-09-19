/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 19:12:37 by spark2            #+#    #+#             */
/*   Updated: 2023/09/19 17:29:13 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_arg
{
	int		infile;
	int		outfile;
	char	**path;
	char	**cmd1;
	char	**cmd2;
	char	*cmd1_path;
	char	*cmd2_path;
	int		pipe_fd[2];
	pid_t	pid;
}	t_arg;

void	check_argc(int argc);
void	check_file(t_arg *arg, char **argv);
char	**get_path_envp(char **envp);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
char	*get_cmd_argv(char **path, char *cmd);
char	*ft_strjoin(char const *s1, char const *s2);
void	run_fork(t_arg *arg, char **envp, int i);
void	free_2d_array(char **str);
void	print_error(char *err_msg);

#endif