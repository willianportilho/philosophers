/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:35:34 by wportilh          #+#    #+#             */
/*   Updated: 2022/11/29 15:27:55 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*life(void *philo)
{
	t_philo	*pointer_philo;

	pointer_philo = (t_philo *) philo;
	printf("%ld Philosopher %d is eating\n", current_time(), pointer_philo->id);
	printf("%ld Philosopher %d is sleeping\n", current_time(), pointer_philo->id);
	printf("%ld Philosopher %d is thinking\n", current_time(), pointer_philo->id);
	printf("n_philo = %d\n", pointer_philo->data->n_philo);
	return (NULL);
}

int	main(void)
{
	t_data		data;

	init(&data);
	while (data.i < data.n_philo)
	{
		pthread_create(data.philo[data.i].philo, NULL, &life, (void *)&data.philo[data.i]);
		data.i++;
	}
	data.i = 0;
	while (data.i < data.n_philo)
	{
		pthread_join(*data.philo[data.i].philo, NULL);
		data.i++;
	}
	clean(&data);
	return (0);
}
