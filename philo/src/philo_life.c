/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willian <willian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 19:24:43 by wportilh          #+#    #+#             */
/*   Updated: 2022/12/08 18:36:30 by willian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static int	drop_a_fork(pthread_mutex_t *fork)
{
	if (pthread_mutex_unlock(fork) != SUCCESS)
		return (FALSE);
	return (TRUE);
}

static int  take_a_fork(pthread_mutex_t *fork, t_philo *ph)
{
	if (pthread_mutex_lock(fork) != SUCCESS)
		return (FALSE);
	if (ph->data->die == TRUE)
		return (FALSE);
	print_status_msg("has taken a fork", ph);
    return (TRUE);
}

void	*life(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *) philo;
	ph->time_to_die_cur = ph->data->initial_time + ph->data->time_to_die;
	while (ph->times_ate != FINISH_EAT)
	{
        if (take_a_fork(&ph->data->forks[ph->fork_left], ph) != TRUE)
            return (drop_a_fork(&ph->data->forks[ph->fork_left]), NULL);
		if (take_a_fork(&ph->data->forks[ph->fork_right], ph) != TRUE)
		{
			drop_a_fork(&ph->data->forks[ph->fork_left]);
			drop_a_fork(&ph->data->forks[ph->fork_right]);
            return (NULL);
		}
		print_status_msg("is eating", ph);
		usleep((ph->data->time_to_eat * 1000));
		if (ph->data->die == TRUE)
		{
			drop_a_fork(&ph->data->forks[ph->fork_left]);
			drop_a_fork(&ph->data->forks[ph->fork_right]);
			return (FALSE);
		}
		ph->time_to_die_cur = current_time() + ph->data->time_to_die;
		if (drop_a_fork(&ph->data->forks[ph->fork_left]) != TRUE)
			return (NULL);
		if (drop_a_fork(&ph->data->forks[ph->fork_right]) != TRUE)
			return (NULL);
		if (--ph->times_ate == 0)
			return (NULL);
		print_status_msg("is sleeping", ph);
		usleep(ph->data->time_to_sleep * 1000);
		if (ph->data->die == TRUE)
			return (FALSE);
		print_status_msg("is thinking", ph);
	}
	return (NULL);
}
