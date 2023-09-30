/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B_free_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 20:15:30 by spark2            #+#    #+#             */
/*   Updated: 2023/09/29 23:03:41 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_2d_array(t_arg *arg, int argc, char **str)
{
	int	i;
	(void)argc;
	(void)arg;
	i = 0;
	while (str[i]) { //문제!!
		free(str[i++]);
	}
	free(str);
}

void	run_free(t_arg *arg, t_cmd *cmd, int argc)
{
	int	i;

	i = -1;
	free_2d_array(arg, argc, arg->path);
	free_2d_array(arg, argc, arg->path_plus_cmd);
	while (++i < argc - 3 - arg->here_flag)
		free_2d_array(arg, argc, cmd->arg[i].arr);
	free(cmd->arg);
}
