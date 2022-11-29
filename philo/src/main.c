/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:35:34 by wportilh          #+#    #+#             */
/*   Updated: 2022/11/29 19:27:20 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	print_message(char *message, t_philo *ph)
{
	pthread_mutex_lock(&ph->data->message);
	printf("%ld philo %d %s\n", current_time(), ph->id, message);
	pthread_mutex_unlock(&ph->data->message);
}

void	*life(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *) philo;
	pthread_mutex_lock(&ph->data->forks[ph->fork_l]);
	print_message("has taken a fork (left)", ph);
	pthread_mutex_lock(&ph->data->forks[ph->fork_r]);
	print_message("has taken a fork (right)", ph);
	usleep(100);
	pthread_mutex_unlock(&ph->data->forks[ph->fork_r]);
	pthread_mutex_unlock(&ph->data->forks[ph->fork_l]);
	return (NULL);
}

int	main(void)
{
	t_data		data;

	init(&data);
	while (data.i < data.n_philo)
	{
		pthread_create(&data.philo_index[data.i].philo_thread, NULL, &life, (void *)&data.philo_index[data.i]);
		data.i++;
		usleep(1000);
	}
	data.i = 0;
	while (data.i < data.n_philo)
	{
		pthread_join(data.philo_index[data.i].philo_thread, NULL);
		data.i++;
	}
	int	i = 0;
	while (i < data.n_philo)
	{
		pthread_mutex_destroy(&data.forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data.message);
	clean(&data);
	return (0);
}
