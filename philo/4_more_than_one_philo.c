/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_more_than_one_philo.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 01:08:40 by wportilh          #+#    #+#             */
/*   Updated: 2022/12/10 23:50:25 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

static int	check_philos(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->n_philos)
	{
		pthread_mutex_lock(&data->time_to_die_cur[i]);
		if (data->philo_index[i].time_to_die_cur < current_time())
		{
			pthread_mutex_unlock(&data->time_to_die_cur[i]);
			if (print_status_msg("die", &data->philo_index[i]) != TRUE)
				return (FALSE);
			pthread_mutex_lock(&data->die_mutex);
			data->die = TRUE;
			usleep(10000);
			pthread_mutex_unlock(&data->die_mutex);
			return (FALSE);
		}
		pthread_mutex_unlock(&data->time_to_die_cur[i]);
		pthread_mutex_lock(&data->times_ate[i]);
		if (data->philo_index[i].times_ate > 0)
			data->check_if_ate++;
		pthread_mutex_unlock(&data->times_ate[i]);
	}
	return (TRUE);
}

static void	*until_dead_or_eat(void *dt)
{
	t_data	*data;

	data = (t_data *) dt;
	while (1)
	{
		usleep(10);
		if (check_philos(data) != TRUE)
			return (NULL);
		if ((data->check_if_ate == 0) && (data->n_times_eat != LIMITLESS))
			return (NULL);
		data->check_if_ate = 0;
	}
	return (NULL);
}

void	start(t_data *data)
{
	int	i;

	i = 0;
	data->initial_time = current_time();
	while (i < data->n_philos)
	{
		pthread_mutex_lock(&data->time_to_die_cur[i]);
		data->philo_index[i].time_to_die_cur = \
		data->initial_time + data->time_to_die;
		pthread_mutex_unlock(&data->time_to_die_cur[i]);
		pthread_create(&data->philo_index[i].philo_thread, NULL, \
			&life, (void *)&data->philo_index[i]);
		i++;
	}
	pthread_create(&data->check, NULL, \
		&until_dead_or_eat, (void *)data);
}
