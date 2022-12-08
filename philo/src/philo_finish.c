/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_finish.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willian <willian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 01:25:53 by wportilh          #+#    #+#             */
/*   Updated: 2022/12/08 17:51:57 by willian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	clean(t_data *data)
{
	free(data->philo_index);
	free(data->forks);
}

int	finish(t_data *data)
{
	int	i;

	i = 0;
	if (pthread_join(data->check, NULL) != SUCCESS)
			return (FALSE);
	while (i < data->n_philos)
	{
		if (pthread_join(data->philo_index[i].philo_thread, NULL) != SUCCESS)
			return (FALSE);
		i++;
	}
	i = 0;
	while (i < data->n_philos)
	{
		if (pthread_mutex_destroy(&data->forks[i]) != SUCCESS)
			return (FALSE);
		i++;
	}
	if (pthread_mutex_destroy(&data->status_msg) != SUCCESS)
		return (FALSE);
	return (TRUE);
}
