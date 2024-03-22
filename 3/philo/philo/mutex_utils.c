/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:31:48 by spark2            #+#    #+#             */
/*   Updated: 2024/01/15 19:50:57 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_philo_dead(t_arg *arg)
{
	int	die;

	die = 0;
	pthread_mutex_lock(&arg->mutex_finish);
	die = arg->finish;
	pthread_mutex_unlock(&arg->mutex_finish);
	return (die);
}

void	update_is_dead(t_arg *arg)
{
	pthread_mutex_lock(&arg->mutex_finish);
	arg->finish = 1;
	pthread_mutex_unlock(&arg->mutex_finish);
}

long long	get_last_meal(t_philo *philo)
{
	long long	last_eat;

	pthread_mutex_lock(&philo->mutex_last_eat);
	last_eat = philo->last_eat;
	pthread_mutex_unlock(&philo->mutex_last_eat);
	return (last_eat);
}

int	check_all_philo_full(t_arg *arg)
{
	int	full_philo_cnt;

	pthread_mutex_lock(&arg->mutex_eat_cnt);
	full_philo_cnt = arg->full_philo_cnt;
	pthread_mutex_unlock(&arg->mutex_eat_cnt);
	if (arg->philo_num == full_philo_cnt)
		return (1);
	return (0);
}

void	print_philo(t_arg *arg, int id, char *msg)
{
	long long	now;
	int			die;

	die = check_philo_dead(arg);
	now = get_current_time();
	pthread_mutex_lock(&(arg->print));
	if (!die)
		printf("%lld %d %s\n", now - arg->start_time, id, msg);
	pthread_mutex_unlock(&(arg->print));
}
