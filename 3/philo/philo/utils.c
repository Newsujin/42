/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:27:16 by spark2            #+#    #+#             */
/*   Updated: 2024/01/15 19:33:34 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int		i;
	long	sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	if ((sign * res) > 2147483647 || (sign * res) < -2147483648)
		return (-1);
	if ((str[i] < '0' || str[i] > '9') && str[i] != 0)
		return (-1);
	return ((int)(sign * res));
}

long	get_current_time(void)
{
	struct timeval	time;
	long			res;

	gettimeofday(&time, NULL);
	res = ((size_t)time.tv_sec * 1000) + ((size_t)time.tv_usec / 1000);
	return (res);
}

void	pass_time(long long wait_time, t_arg *arg)
{
	long long	start;
	long long	now;
	int			die;

	start = get_current_time();
	while (1)
	{
		die = check_philo_dead(arg);
		if (die)
			break ;
		now = get_current_time();
		if ((now - start) >= wait_time)
			break ;
		usleep(100);
	}
}

int	print_error(char *msg, int fd)
{
	printf("%s\n", msg);
	return (fd);
}
