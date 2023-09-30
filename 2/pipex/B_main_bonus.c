 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B_main_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 19:12:18 by spark2            #+#    #+#             */
/*   Updated: 2023/09/29 17:20:37 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	check()
{
	system("leaks pipex_bonus");
}

int	main(int argc, char **argv, char **envp)
{
	t_arg	arg;
	t_cmd	cmd;

	ft_memset(&arg, 0, sizeof(t_arg));
	check_argc(argc);
	set_file(&arg, argc, argv);
	if (arg.here_flag)
		run_heredoc(&arg, argv[2]);
	get_path_envp(&arg, envp);
	set_cmd(&arg, &cmd, argc, argv);
	run_fork(&arg, &cmd, argc, envp);
	run_free(&arg, &cmd, argc);
	unlink("/tmp/.infile"); //다른 곳에서 exit 하는 경우에도 필요함
	atexit(check);
}
