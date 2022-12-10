/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_life.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 19:24:43 by wportilh          #+#    #+#             */
/*   Updated: 2022/12/10 03:00:00 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

static int	take_forks(t_philo *ph)
{
	pthread_mutex_lock(&ph->data->forks[ph->fork_left]);
	pthread_mutex_lock(&ph->data->die_mutex);
	if (ph->data->die == TRUE)
	{
		pthread_mutex_unlock(&ph->data->die_mutex);
		pthread_mutex_unlock(&ph->data->forks[ph->fork_left]);
		return (FALSE);
	}
	pthread_mutex_unlock(&ph->data->die_mutex);
	print_status_msg("has taken a fork", ph);
	pthread_mutex_lock(&ph->data->forks[ph->fork_right]);
	pthread_mutex_lock(&ph->data->die_mutex);
	if (ph->data->die == TRUE)
	{
		pthread_mutex_unlock(&ph->data->die_mutex);
		pthread_mutex_unlock(&ph->data->forks[ph->fork_left]);
		pthread_mutex_unlock(&ph->data->forks[ph->fork_right]);
		return (FALSE);
	}
	pthread_mutex_unlock(&ph->data->die_mutex);
	print_status_msg("has taken a fork", ph);
	return (TRUE);
}

static int	philo_eat(t_philo *ph)
{
	print_status_msg("is eating", ph);
	usleep(ph->data->time_to_eat * 1000);
	pthread_mutex_lock(&ph->data->die_mutex);
	if (ph->data->die == TRUE)
	{
		pthread_mutex_unlock(&ph->data->die_mutex);
		pthread_mutex_unlock(&ph->data->forks[ph->fork_left]);
		pthread_mutex_unlock(&ph->data->forks[ph->fork_right]);
		return (FALSE);
	}
	pthread_mutex_unlock(&ph->data->die_mutex);
	pthread_mutex_lock(&ph->data->time_to_die_cur[ph->id - 1]);
	ph->time_to_die_cur = current_time() + ph->data->time_to_die;
	pthread_mutex_unlock(&ph->data->time_to_die_cur[ph->id - 1]);
	pthread_mutex_unlock(&ph->data->forks[ph->fork_left]);
	pthread_mutex_unlock(&ph->data->forks[ph->fork_right]);
	pthread_mutex_lock(&ph->data->times_ate[ph->id - 1]);
	if (--ph->times_ate == 0)
	{
		pthread_mutex_unlock(&ph->data->times_ate[ph->id - 1]);
		return (FALSE);
	}
	pthread_mutex_unlock(&ph->data->times_ate[ph->id - 1]);
	return (TRUE);
}

static void	philo_sleep(t_philo *ph)
{
	print_status_msg("is sleeping", ph);
	usleep(ph->data->time_to_sleep * 1000);
	pthread_mutex_lock(&ph->data->die_mutex);
	if (ph->data->die == TRUE)
	{
		pthread_mutex_unlock(&ph->data->die_mutex);
		return ;
	}
	pthread_mutex_unlock(&ph->data->die_mutex);
}

static void	philo_think(t_philo *ph)
{
	print_status_msg("is thinking", ph);
}

void	*life(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *) philo;
	while ((pthread_mutex_lock(&ph->data->times_ate[ph->id - 1]) == 0) \
	&& (ph->times_ate != FINISH_EAT))
	{
		pthread_mutex_unlock(&ph->data->times_ate[ph->id - 1]);
		if (take_forks(ph) != TRUE)
			return (NULL);
		if (philo_eat(ph) != TRUE)
			return (NULL);
		philo_sleep(ph);
		philo_think(ph);
	}
	pthread_mutex_unlock(&ph->data->times_ate[ph->id - 1]);
	return (NULL);
}
