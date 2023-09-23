/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B_set_cmd_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 20:23:06 by spark2            #+#    #+#             */
/*   Updated: 2023/09/23 21:34:58 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	set_cmd(t_arg *arg, t_cmd *cmd, int argc, char **argv)
{
	int	i;

	i = -1;
	cmd->arg = (t_cmd_arg *)malloc(sizeof(t_cmd_arg) * (argc - 2));
	arg->path_plus_cmd = (char **)malloc(sizeof(char *) * (argc - 2));
	while (++i < argc - 3)
	{
		cmd->arg[i].arr = ft_split(argv[i + 2], ' ');
		if (cmd->arg[i].arr == NULL)
			print_error("cmd split error");
		arg->path_plus_cmd[i] = get_cmd_path(arg->path, cmd->arg[i].arr[0]);
	}
	cmd->arg[i].arr = 0;
	cmd->arg[i].arr = 0;
}
