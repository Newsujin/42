/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   M_check.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:46:12 by spark2            #+#    #+#             */
/*   Updated: 2023/10/03 15:31:02 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_argc(int argc)
{
	if (argc != 5)
		print_error("argc error\n");
}

void	set_file(t_arg *arg, char **argv)
{
	arg->infile = open(argv[1], O_RDONLY);
	arg->outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
}
