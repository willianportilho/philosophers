/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_finish.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 01:25:53 by wportilh          #+#    #+#             */
/*   Updated: 2022/12/09 23:22:09 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	clean(t_data *data)
{
	free(data->philo_index);
	free(data->forks);
	free(data->time_to_die_cur);
	free(data->times_ate);
}

int	finish(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->n_philos)
	{
		if (pthread_join(data->philo_index[i].philo_thread, NULL) != SUCCESS)
			return (FALSE);
	}
	if (pthread_join(data->check, NULL) != SUCCESS)
		return (FALSE);
	i = -1;
	while (++i < data->n_philos)
	{
		if (pthread_mutex_destroy(&data->forks[i]) != SUCCESS)
			return (FALSE);
		if (pthread_mutex_destroy(&data->time_to_die_cur[i]) != SUCCESS)
			return (FALSE);
		if (pthread_mutex_destroy(&data->times_ate[i]) != SUCCESS)
			return (FALSE);
	}
	if (pthread_mutex_destroy(&data->status_msg) != SUCCESS)
		return (FALSE);
	if (pthread_mutex_destroy(&data->die_mutex) != SUCCESS)
		return (FALSE);
	return (TRUE);
}
