/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   M_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 19:12:18 by spark2            #+#    #+#             */
/*   Updated: 2023/10/03 15:17:01 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	leaks()
{
	system("leaks pipex");
}

int	main(int argc, char **argv, char **envp)
{
	t_arg	arg;
	t_cmd	cmd;

	ft_memset(&arg, 0, sizeof(t_arg));
	check_argc(argc);
	set_file(&arg, argv);
	get_path_envp(&arg, envp);
	set_cmd(&cmd, argv);
	run_fork(&arg, &cmd, envp);
	run_free(&arg, &cmd);
	atexit(leaks);
}
