/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 13:52:29 by spark2            #+#    #+#             */
/*   Updated: 2024/01/15 17:31:47 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_arg(t_arg *arg, int argc, char **argv)
{
	arg->philo_num = ft_atoi(argv[1]);
	arg->time_to_die = ft_atoi(argv[2]);
	arg->time_to_eat = ft_atoi(argv[3]);
	arg->time_to_sleep = ft_atoi(argv[4]);
	arg->start_time = get_current_time();
	arg->full_philo_cnt = 0;
	arg->finish = 0;
	if (arg->philo_num <= 0 || arg->time_to_die < 0 || \
		arg->time_to_eat < 0 || arg->time_to_sleep < 0)
		return (1);
	if (argc == 6)
	{
		arg->must_eat_num = ft_atoi(argv[5]);
		if (arg->must_eat_num <= 0)
			return (1);
		if (arg->philo_num == 1)
			arg->must_eat_num = -1;
	}
	else
		arg->must_eat_num = -1;
	return (0);
}

int	init_philo(t_arg *arg)
{
	int		i;

	i = 0;
	arg->philo = malloc(sizeof(t_philo) * arg->philo_num);
	if (!arg->philo)
		return (1);
	while (i < arg->philo_num)
	{
		arg->philo[i].id = i + 1;
		arg->philo[i].eat_cnt = 0;
		arg->philo[i].left = i;
		arg->philo[i].right = (i + 1) % arg->philo_num;
		arg->philo[i].last_eat = 0;
		arg->philo[i].arg = arg;
		i++;
	}
	return (0);
}

int	init_mutex(t_arg *arg)
{
	int	i;

	i = 0;
	arg->fork = malloc(sizeof(pthread_mutex_t) * arg->philo_num);
	if (!(arg->fork))
		return (1);
	while (i < arg->philo_num)
	{
		if (pthread_mutex_init(&(arg->fork[i]), NULL)
			|| pthread_mutex_init(&(arg->philo[i].mutex_last_eat), NULL))
			return (1);
		i++;
	}
	if (pthread_mutex_init(&arg->print, NULL)
		|| pthread_mutex_init(&arg->mutex_finish, NULL)
		|| pthread_mutex_init(&arg->mutex_eat_cnt, NULL))
		return (1);
	return (0);
}
