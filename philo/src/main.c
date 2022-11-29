/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:35:34 by wportilh          #+#    #+#             */
/*   Updated: 2022/11/29 17:40:24 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*life(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *) philo;
	pthread_mutex_lock(&ph->data->forks[ph->fork_l]);
	printf("%ld Philosopher %d has taken a fork left\n", current_time(), ph->id);
	pthread_mutex_lock(&ph->data->forks[ph->fork_r]);
	printf("%ld Philosopher %d has taken a fork right\n", current_time(), ph->id);
	usleep(3000000);
	pthread_mutex_unlock(&ph->data->forks[ph->fork_l]);
	pthread_mutex_unlock(&ph->data->forks[ph->fork_r]);
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
		//if ((data.i % 2) == 0)
		//	usleep(1000);
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
	clean(&data);
	return (0);
}
