/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willian <willian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 01:08:40 by wportilh          #+#    #+#             */
/*   Updated: 2022/12/09 18:58:50 by willian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

long long	current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_usec / 1000) + (time.tv_sec * 1000));
}

int	print_status_msg(char *status_msg, t_philo *ph)
{
	if (pthread_mutex_lock(&ph->data->status_msg) != SUCCESS)
		return (FALSE);
	printf("%lld philo %d %s\n", \
	(current_time() - ph->data->initial_time), ph->id, status_msg);
	if (pthread_mutex_unlock(&ph->data->status_msg) != SUCCESS)
		return (FALSE);
	return (TRUE);
}

static void	*until_dead_or_eat(void *dt)
{
	int		i;
	int		check_if_ate;
	t_data	*data;

	i = -1;
	check_if_ate = 0;
	data = (t_data *) dt;
	while (1)
	{
		while (++i < data->n_philos)
		{
			pthread_mutex_lock(&data->time_to_die_cur[i]);
			if (data->philo_index[i].time_to_die_cur <= current_time())
			{
				pthread_mutex_unlock(&data->time_to_die_cur[i]);
				print_status_msg("die", &data->philo_index[i]);
				pthread_mutex_lock(&data->die_mutex);
				data->die = TRUE;
				pthread_mutex_unlock(&data->die_mutex);
				return (NULL);
			}
			pthread_mutex_unlock(&data->time_to_die_cur[i]);
			pthread_mutex_lock(&data->times_ate[i]);
			if (data->philo_index[i].times_ate > 0)
				check_if_ate++;
			pthread_mutex_unlock(&data->times_ate[i]);
		}
		if ((check_if_ate == 0) && (data->n_times_eat != LIMITLESS))
			return (NULL);
		check_if_ate = 0;
		i = -1;
	}
	return (NULL);
}

int	start_one(t_data *data)
{
	data->initial_time = current_time();
	if (pthread_create(&data->philo_index[0].philo_thread, \
		NULL, &life_one, (void *)&data->philo_index[0]) == -1)
		return (FALSE);
	if (pthread_join(data->philo_index[0].philo_thread, NULL) != SUCCESS)
			return (FALSE);
	if (pthread_mutex_destroy(&data->forks[0]) != SUCCESS)
		return (FALSE);
	if (pthread_mutex_destroy(&data->status_msg) != SUCCESS)
		return (FALSE);
	return (TRUE);
}

int	start(t_data *data)
{
	int	i;

	i = 0;
	data->initial_time = current_time();
	while (i < data->n_philos)
	{
		pthread_mutex_lock(&data->time_to_die_cur[i]);
		if ((i % 2) == 0)
			data->philo_index[i].time_to_die_cur = data->initial_time + data->time_to_die + 1000;
		else
			data->philo_index[i].time_to_die_cur = data->initial_time + data->time_to_die;
		pthread_mutex_unlock(&data->time_to_die_cur[i]);
		if (pthread_create(&data->philo_index[i].philo_thread, \
		NULL, &life, (void *)&data->philo_index[i]) == -1)
			return (FALSE);
		if ((i % 2) == 0)
			usleep(1000);
		i++;
	}
	if (pthread_create(&data->check, NULL, &until_dead_or_eat, (void *)data) == -1)
		return (FALSE);
	return (TRUE);
}
