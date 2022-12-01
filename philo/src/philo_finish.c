/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_finish.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 01:25:53 by wportilh          #+#    #+#             */
/*   Updated: 2022/12/01 03:50:09 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	finish(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philos)
	{
		if (pthread_join(data->philo_index[i].philo_thread, NULL) != SUCCESS)
		{
			printf("pthread_join error\n");
			return (FALSE);
		}
		i++;
	}
	i = 0;
	while (i < data->n_philos)
	{
		if (pthread_mutex_destroy(&data->forks[i]) != SUCCESS)
		{
			printf("pthread_mutex_destroy (forks) error\n");
			return (FALSE);
		}
		i++;
	}
	if (pthread_mutex_destroy(&data->status_msg) != SUCCESS)
	{
		printf("pthread_mutex_destroy (status) error\n");
		return (FALSE);
	}
	return (TRUE);
}
