/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 13:27:39 by spark2            #+#    #+#             */
/*   Updated: 2024/01/15 20:12:15 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_arg
{
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_num;
	int				full_philo_cnt;
	long			start_time;
	int				finish;
	struct s_philo	*philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	pthread_mutex_t	mutex_finish;
	pthread_mutex_t	mutex_eat_cnt;
}	t_arg;

typedef struct s_philo
{
	int				id;
	int				eat_cnt;
	int				left;
	int				right;
	long			last_eat;
	t_arg			*arg;
	pthread_t		thread;
	pthread_mutex_t	mutex_last_eat;
}	t_philo;

/* init */
int			init_arg(t_arg *arg, int argc, char **argv);
int			init_philo(t_arg *arg);
int			init_mutex(t_arg *arg);

/* mutex_utils */
int			check_philo_dead(t_arg *arg);
void		update_is_dead(t_arg *arg);
long long	get_last_meal(t_philo *philo);
int			check_all_philo_full(t_arg *arg);
void		print_philo(t_arg *arg, int id, char *msg);

/* philo */
int			is_over_dead_time(t_arg *arg, int i);
void		monitoring(t_arg *arg);
void		eating(t_arg *arg, t_philo *philo);
void		*ft_thread(void *argv);
int			start_philo(t_arg *arg, t_philo *philo);

/* utils */
int			ft_atoi(const char *str);
long		get_current_time(void);
void		pass_time(long long wait_time, t_arg *arg);
int			print_error(char *msg, int fd);

#endif
