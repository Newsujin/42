/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B_here_doc_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 19:34:50 by spark2            #+#    #+#             */
/*   Updated: 2023/09/30 22:10:05 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "get_next_line/get_next_line.c"
#include "get_next_line/get_next_line_utils.c"

void	run_heredoc(t_arg *arg, char *limiter)
{
	char	*gnl;

	arg->infile = open("/tmp/.infile", O_CREAT | O_WRONLY | O_TRUNC, 0666);
	while (1)
	{
		gnl = get_next_line(0);
		if (!ft_strncmp_gnl(limiter, gnl, ft_strlen(limiter)))
			break ;
		write(arg->infile, gnl, ft_strlen(gnl));
		free(gnl);
	}
	if (gnl)
		free(gnl);
	close(arg->infile);
	arg->infile = open("/tmp/.infile", O_RDONLY, 0644);
}
