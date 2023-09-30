/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   M_path.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 19:32:37 by spark2            #+#    #+#             */
/*   Updated: 2023/09/30 16:38:31 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "./libft/ft_strjoin.c"

/* 환경변수에서 PATH를 찾아서 PATH= 이후의 글자를 ft_split 으로 : 를 기준으로 나눠서 저장 */
void	get_path_envp(t_arg *arg, char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	arg->path = ft_split(*envp + 5, ':');
}

/* command를 가져온 다음 실행 가능한 PATH가 존재하는지 확인 */
char	*get_cmd_path(char **path, char *cmd)
{
	int		i;
	int		flag;
	char	*path_cmd;
	char	*tmp;

	if (!access(cmd, X_OK))
	{
		cmd = ft_strdup(cmd);
		return (cmd);
	}
	path_cmd = ft_strjoin("/", cmd);
	flag = 0;
	i = -1;
	while (path[++i])
	{
		tmp = ft_strjoin(path[i], path_cmd);
		flag = access(tmp, X_OK);
		if (flag == 0)
		{
			free(path_cmd);
			return (tmp);
		}
		free(tmp);
	}
	free(path_cmd);
	printf("here\n");
	// print_error("wrong command error\n");
	return (NULL);
}
