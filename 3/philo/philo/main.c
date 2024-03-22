/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 13:30:19 by spark2            #+#    #+#             */
/*   Updated: 2024/01/15 20:11:31 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_arg	arg;

	if (argc != 5 && argc != 6)
		return (print_error("argc error", 2));
	if (init_arg(&arg, argc, argv))
		return (print_error("init arg error", 2));
	if (init_philo(&arg))
		return (print_error("init philo error", 2));
	if (init_mutex(&arg))
		return (print_error("init mutex error", 2));
	if (start_philo(&arg, arg.philo))
		return (print_error("start philo error", 2));
}
