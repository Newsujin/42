/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B_path_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 19:32:37 by spark2            #+#    #+#             */
/*   Updated: 2023/10/03 17:16:40 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	get_path_envp(t_arg *arg, char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	arg->path = ft_split(*envp + 5, ':');
}

char	*get_cmd_path(char **path, char *cmd)
{
	char	*path_cmd;
	char	*tmp;

	if (!access(cmd, X_OK))
		return (ft_strdup(cmd));
	path_cmd = ft_strjoin("/", cmd);
	while (*path)
	{
		tmp = ft_strjoin(*path, path_cmd);
		if (!access(tmp, X_OK))
		{
			free(path_cmd);
			return (tmp);
		}
		free(tmp);
		path++;
	}
	free(path_cmd);
	if (!access(cmd, F_OK))
		print_error("permission denied\n");
	print_error("command not found\n");
	return (NULL);
}
