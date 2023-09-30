/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   M_error.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 21:18:11 by spark2            #+#    #+#             */
/*   Updated: 2023/09/30 22:32:47 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_error(char *err_msg)
{
	perror(err_msg);
	exit(1);
}
