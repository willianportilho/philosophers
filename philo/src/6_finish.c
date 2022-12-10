/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 01:25:53 by wportilh          #+#    #+#             */
/*   Updated: 2022/12/10 02:19:34 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	finish(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->n_philos)
		pthread_join(data->philo_index[i].philo_thread, NULL);
	if (data->n_philos > 1)
		pthread_join(data->check, NULL);
	i = -1;
	while (++i < data->n_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->time_to_die_cur[i]);
		pthread_mutex_destroy(&data->times_ate[i]);
	}
	pthread_mutex_destroy(&data->status_msg);
	pthread_mutex_destroy(&data->die_mutex);
}
