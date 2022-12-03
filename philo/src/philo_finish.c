/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_finish.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 01:25:53 by wportilh          #+#    #+#             */
/*   Updated: 2022/12/03 19:27:58 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	clean(t_data *data)
{
	free(data->philo_index);
	free(data->forks);
	free(data->fork_is_lock);
}

int	finish(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philos)
	{
		if (pthread_join(data->philo_index[i].philo_thread, NULL) != SUCCESS)
			return (print_message_error("error: pthread_join"));
		i++;
	}
	i = 0;
	while (i < data->n_philos)
	{
		if (pthread_mutex_destroy(&data->forks[i]) != SUCCESS)
			return (print_message_error("error: pthread_mutex_destroy (forks)"));
		i++;
	}
	if (pthread_mutex_destroy(&data->status_msg) != SUCCESS)
		return (print_message_error("error: pthread_mutex_destroy (status)"));
	return (TRUE);
}
