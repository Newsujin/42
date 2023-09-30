/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B_check_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:46:12 by spark2            #+#    #+#             */
/*   Updated: 2023/09/29 21:37:09 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	check_argc(int argc)
{
	if (argc < 5)
	{
		write(1, "argument error\n", 15);
		exit(1);
	}
}

void	check_file(t_arg *arg, int argc, char **argv)
{
	if (!ft_strncmp(argv[1], "here_doc", 8))
	{
		arg->here_flag = 1;
		arg->outfile = open(argv[argc - 1], O_RDWR | O_CREAT | O_APPEND, 0644);
	}
	else
	{
		arg->infile = open(argv[1], O_RDONLY);
		arg->outfile = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	}
	// if (arg->infile == -1)
	// 	print_error("Could not open infile");
	// if (arg->outfile == -1)
	// 	print_error("Outfile error");
}
