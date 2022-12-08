/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 01:08:40 by wportilh          #+#    #+#             */
/*   Updated: 2022/12/03 19:29:00 by wportilh         ###   ########.fr       */
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
		return (print_message_error("error: pthread_mutex_lock (status_msg)"));
	printf("%lld philo %d %s\n", \
	(current_time() - ph->data->initial_time), ph->id, status_msg);
	if (pthread_mutex_unlock(&ph->data->status_msg) != SUCCESS)
		return (print_message_error("error: pthread_mutex_unlock (status_msg)"));
	return (TRUE);
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
			return (print_message_error("error: pthread_create"));
		if ((i % 2) == 0)
			usleep(LAG);
		i++;
	}
	return (TRUE);
}
