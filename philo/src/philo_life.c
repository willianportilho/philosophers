/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willian <willian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 19:24:43 by wportilh          #+#    #+#             */
/*   Updated: 2022/12/08 16:48:12 by willian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"


static int	drop_forks(t_philo *ph)
{
	if (pthread_mutex_unlock(&ph->data->forks[ph->fork_left]) != SUCCESS)
		return (FALSE);
	if (pthread_mutex_unlock(&ph->data->forks[ph->fork_right]) != SUCCESS)
		return (FALSE);
	return (TRUE);
}

static int  take_forks(t_philo *ph)
{
	if (pthread_mutex_lock(&ph->data->forks[ph->fork_left]) != SUCCESS)
		return (FALSE);
	print_status_msg("has taken a fork", ph);
	if (pthread_mutex_lock(&ph->data->forks[ph->fork_right]) != SUCCESS)
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
        if (take_forks(ph) != TRUE)
            return (NULL);
		print_status_msg("is eating", ph);
		usleep((ph->data->time_to_eat * 1000));
		ph->time_to_die_cur = current_time() + ph->data->time_to_die;
		if (drop_forks(ph) != TRUE)
			return (NULL);
		if (--ph->times_ate == 0)
			return (NULL);
		print_status_msg("is sleeping", ph);
		usleep(ph->data->time_to_sleep * 1000);
		print_status_msg("is thinking", ph);
	}
	return (NULL);
}
