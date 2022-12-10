/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willian <willian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 01:02:54 by wportilh          #+#    #+#             */
/*   Updated: 2022/12/10 00:27:00 by willian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

long long	current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_usec / 1000) + (time.tv_sec * 1000));
}

int	print_status_msg(char *status_msg, t_philo *ph)
{
	pthread_mutex_lock(&ph->data->status_msg);
	pthread_mutex_lock(&ph->data->die_mutex);
	if (ph->data->die == TRUE)
	{
		pthread_mutex_unlock(&ph->data->status_msg);
		pthread_mutex_unlock(&ph->data->die_mutex);
		return (FALSE);
	}
	pthread_mutex_unlock(&ph->data->die_mutex);
	printf("%lld %d %s\n", \
	(current_time() - ph->data->initial_time), ph->id, status_msg);
	pthread_mutex_unlock(&ph->data->status_msg);
	return (TRUE);
}

int	print_message_error(char *message)
{
	printf("%s\n", message);
	return (FALSE);
}

void	clean(t_data *data)
{
	free(data->philo_index);
	free(data->forks);
	free(data->time_to_die_cur);
	free(data->times_ate);
}
