/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   M_set_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 20:59:50 by spark2            #+#    #+#             */
/*   Updated: 2023/09/29 18:01:27 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	set_cmd(t_arg *arg, t_cmd *cmd, char **argv)
{
	int	i;

	i = -1;
	cmd->arg = (t_cmd_arg *)malloc(sizeof(t_cmd_arg) * 3);
	arg->path_plus_cmd = (char **)malloc(sizeof(char *) * 3);
	while (++i < 2)
	{
		cmd->arg[i].arr = ft_split(argv[i + 2], ' ');
		if (cmd->arg[i].arr == NULL)
			print_error("cmd split error");
		arg->path_plus_cmd[i] = get_cmd_path(arg->path, cmd->arg[i].arr[0]);
	}
	cmd->arg[i].arr = 0;
	cmd->arg[i].arr = 0;
}
