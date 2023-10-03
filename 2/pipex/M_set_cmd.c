/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   M_set_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 20:59:50 by spark2            #+#    #+#             */
/*   Updated: 2023/10/03 15:35:36 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	set_cmd(t_cmd *cmd, char **argv)
{
	int	i;

	i = -1;
	cmd->arg = (t_cmd_arg *)malloc(sizeof(t_cmd_arg) * 3);
	while (++i < 2)
	{
		cmd->arg[i].arr = ft_split(argv[i + 2], ' ');
		if (cmd->arg[i].arr == NULL)
			print_error("cmd split error\n");
	}
	cmd->arg[i].arr = 0;
}
