/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 19:24:43 by wportilh          #+#    #+#             */
/*   Updated: 2022/12/09 23:36:29 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void	drop_a_fork(pthread_mutex_t *fork)
{
	pthread_mutex_unlock(fork);
}

static int	take_a_fork(pthread_mutex_t *fork, t_philo *ph)
{
	pthread_mutex_lock(fork);
	pthread_mutex_lock(&ph->data->die_mutex);
	if (ph->data->die == TRUE)
	{
		pthread_mutex_unlock(&ph->data->die_mutex);
		return (FALSE);
	}
	pthread_mutex_unlock(&ph->data->die_mutex);
	print_status_msg("has taken a fork", ph);
	return (TRUE);
}

void	*life(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *) philo;
	while ((pthread_mutex_lock(&ph->data->times_ate[ph->id - 1]) == 0) \
	&& (ph->times_ate != FINISH_EAT))
	{
		pthread_mutex_unlock(&ph->data->times_ate[ph->id - 1]);
		if (take_a_fork(&ph->data->forks[ph->fork_left], ph) != TRUE)
			return (drop_a_fork(&ph->data->forks[ph->fork_left]), NULL);
		if (take_a_fork(&ph->data->forks[ph->fork_right], ph) != TRUE)
		{
			drop_a_fork(&ph->data->forks[ph->fork_left]);
			drop_a_fork(&ph->data->forks[ph->fork_right]);
			return (NULL);
		}
		print_status_msg("is eating", ph);
		usleep(ph->data->time_to_eat * 1000);
		pthread_mutex_lock(&ph->data->die_mutex);
		if (ph->data->die == TRUE)
		{
			pthread_mutex_unlock(&ph->data->die_mutex);
			drop_a_fork(&ph->data->forks[ph->fork_left]);
			drop_a_fork(&ph->data->forks[ph->fork_right]);
			return (FALSE);
		}
		pthread_mutex_unlock(&ph->data->die_mutex);
		pthread_mutex_lock(&ph->data->time_to_die_cur[ph->id - 1]);
		ph->time_to_die_cur = current_time() + ph->data->time_to_die;
		pthread_mutex_unlock(&ph->data->time_to_die_cur[ph->id - 1]);
		drop_a_fork(&ph->data->forks[ph->fork_left]);
		drop_a_fork(&ph->data->forks[ph->fork_right]);
		pthread_mutex_lock(&ph->data->times_ate[ph->id - 1]);
		if (--ph->times_ate == 0)
		{
			pthread_mutex_unlock(&ph->data->times_ate[ph->id - 1]);
			return (NULL);
		}
		pthread_mutex_unlock(&ph->data->times_ate[ph->id - 1]);
		print_status_msg("is sleeping", ph);
		usleep(ph->data->time_to_sleep * 1000);
		pthread_mutex_lock(&ph->data->die_mutex);
		if (ph->data->die == TRUE)
		{
			pthread_mutex_unlock(&ph->data->die_mutex);
			return (FALSE);
		}
		pthread_mutex_unlock(&ph->data->die_mutex);
		print_status_msg("is thinking", ph);
	}
	pthread_mutex_unlock(&ph->data->times_ate[ph->id - 1]);
	return (NULL);
}

void	*life_one(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *) philo;
	ph->time_to_die_cur = ph->data->initial_time + ph->data->time_to_die;
	if (take_a_fork(&ph->data->forks[ph->fork_right], ph) != TRUE)
		return (drop_a_fork(&ph->data->forks[ph->fork_right]), NULL);
	while (1)
	{
		if (ph->time_to_die_cur <= current_time())
		{
			drop_a_fork(&ph->data->forks[ph->fork_right]);
			print_status_msg("die", ph);
			return (NULL);
		}
	}
	return (NULL);
}
