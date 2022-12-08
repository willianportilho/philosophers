/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willian <willian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 01:08:40 by wportilh          #+#    #+#             */
/*   Updated: 2022/12/08 18:31:56 by willian          ###   ########.fr       */
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

void	*until_dead(void *dt)
{
	int		i;
	t_data	*data;

	i = -1;
	data = (t_data *) dt;
	while (1)
	{
		while (++i < data->n_philos)
		{
			if (data->philo_index[i].time_to_die_cur <= current_time())
			{
				print_status_msg("die", &data->philo_index[i]);
				data->die = TRUE;
				return (NULL);
			}
		}
		i = -1;
	}
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
			return (FALSE);
		if ((i % 2) == 0)
			usleep(50);
		i++;
	}
	usleep(1000);
	if (pthread_create(&data->check, NULL, &until_dead, (void *)data) == -1)
		return (FALSE);
	return (TRUE);
}
