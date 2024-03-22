/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:43:23 by spark2            #+#    #+#             */
/*   Updated: 2024/01/15 20:07:15 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_over_dead_time(t_arg *arg, int i)
{
	long long	now;
	long long	last_eat;

	now = get_current_time();
	last_eat = get_last_meal(&(arg->philo[i]));
	if ((now - last_eat) >= arg->time_to_die)
	{
		print_philo(arg, i + 1, "died");
		update_is_dead(arg);
		return (1);
	}
	return (0);
}

void	monitoring(t_arg *arg)
{
	int	i;

	while (1)
	{
		if (arg->philo_num != 1 && check_all_philo_full(arg))
		{
			update_is_dead(arg);
			break ;
		}
		i = 0;
		while (i < arg->philo_num)
		{
			if (is_over_dead_time(arg, i))
				return ;
			i++;
		}
	}
}

void	eating(t_arg *arg, t_philo *philo)
{
	pthread_mutex_lock(&(arg->fork[philo->left]));
	print_philo(arg, philo->id, "has taken a fork");
	if (arg->philo_num != 1)
	{
		pthread_mutex_lock(&(arg->fork[philo->right]));
		print_philo(arg, philo->id, "has taken a fork");
		print_philo(arg, philo->id, "is eating");
		pthread_mutex_lock(&(philo->mutex_last_eat));
		philo->last_eat = get_current_time();
		pthread_mutex_unlock(&(philo->mutex_last_eat));
		philo->eat_cnt++;
		pass_time((long long)arg->time_to_eat, arg);
		pthread_mutex_lock(&arg->mutex_eat_cnt);
		if (arg->must_eat_num == philo->eat_cnt)
			arg->full_philo_cnt++;
		pthread_mutex_unlock(&arg->mutex_eat_cnt);
		pthread_mutex_unlock(&(arg->fork[philo->right]));
	}
	pthread_mutex_unlock(&(arg->fork[philo->left]));
}

void	*ft_thread(void *argv)
{
	t_arg	*arg;
	t_philo	*philo;
	int		die;

	philo = argv;
	arg = philo->arg;
	if (!(philo->id % 2) && arg->philo_num != 1)
		pass_time((long long)arg->time_to_eat, arg);
	while (1)
	{
		die = check_philo_dead(arg);
		if (die || arg->must_eat_num == philo->eat_cnt)
			break ;
		eating(arg, philo);
		if (arg->philo_num == 1)
			break ;
		print_philo(arg, philo->id, "is sleeping");
		pass_time((long long)arg->time_to_sleep, arg);
		print_philo(arg, philo->id, "is thinking");
	}
	return (0);
}

int	start_philo(t_arg *arg, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < arg->philo_num)
	{
		pthread_mutex_lock(&philo->mutex_last_eat);
		philo[i].last_eat = get_current_time();
		pthread_mutex_unlock(&philo->mutex_last_eat);
		if (pthread_create(&(philo[i].thread), NULL, ft_thread, &(philo[i])))
			return (1);
	}
	monitoring(arg);
	i = -1;
	while (++i < arg->philo_num)
		pthread_join(philo[i].thread, NULL);
	free(arg->philo);
	free(arg->fork);
	return (0);
}
