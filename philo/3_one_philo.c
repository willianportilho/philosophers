/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_one_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 01:48:22 by wportilh          #+#    #+#             */
/*   Updated: 2022/12/11 02:46:23 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

static void	*life_one(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *) philo;
	ph->time_to_die_cur = ph->data->initial_time + ph->data->time_to_die;
	pthread_mutex_lock(&ph->data->forks[ph->fork_right]);
	print_status_msg("has taken a fork", ph);
	while (1)
	{
		usleep(10);
		if (ph->time_to_die_cur < current_time())
		{
			pthread_mutex_unlock(&ph->data->forks[ph->fork_right]);
			print_status_msg("died", ph);
			return (NULL);
		}
	}
	return (NULL);
}

void	start_one_philo(t_data *data)
{
	data->initial_time = current_time();
	pthread_create(&data->philo_index[0].philo_thread, NULL, \
		&life_one, (void *)&data->philo_index[0]);
}
