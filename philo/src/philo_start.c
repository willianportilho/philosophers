/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 01:08:40 by wportilh          #+#    #+#             */
/*   Updated: 2022/12/01 04:06:44 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	print_status_msg(char *status_msg, t_philo *ph)
{
	pthread_mutex_lock(&ph->data->status_msg);
	printf("%lld philo %d %s\n", \
	current_time() - ph->data->initial_time, ph->id, status_msg);
	pthread_mutex_unlock(&ph->data->status_msg);
}

static void	*life(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *) philo;
	pthread_mutex_lock(&ph->data->forks[ph->fork_l]);
	print_status_msg("has taken a fork (left)", ph);
	pthread_mutex_lock(&ph->data->forks[ph->fork_r]);
	print_status_msg("has taken a fork (right)", ph);
	usleep(300);
	pthread_mutex_unlock(&ph->data->forks[ph->fork_r]);
	pthread_mutex_unlock(&ph->data->forks[ph->fork_l]);
	return (NULL);
}

int	start(t_data *data)
{
	int	i;

	i = 0;
	data->initial_time = current_time();
	while (i < data->n_philos)
	{
		if (pthread_create(&data->philo_index[i].philo_thread, \
		NULL, &life, (void *)&data->philo_index[i]) == -1)
		{
			printf("pthread_create error\n");
			return (FALSE);
		}
		if ((i % 2) == 0)
			usleep(10);
		i++;
	}
	return (TRUE);
}
