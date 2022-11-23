/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beatriz <beatriz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:35:34 by wportilh          #+#    #+#             */
/*   Updated: 2022/11/23 13:38:02 by beatriz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*life(void *philo)
{
	t_philo	*pointer_philo;

	pointer_philo = (t_philo *) philo;
	printf("Philosopher %d is eating\n", pointer_philo->id);
	printf("Philosopher %d is sleeping\n", pointer_philo->id);
	printf("Philosopher %d is thinking\n", pointer_philo->id);
	return (NULL);
}

int	main(void)
{
	t_data		data;

	init(&data);
	while (data.i < 2)
	{
		data.philo[data.i].id = data.i + 1;
		pthread_create(data.philo[data.i].philo, NULL, &life, (void *)&data.philo[data.i]);
		data.i++;
	}
	data.i = 0;
	while (data.i < 2)
	{
		pthread_join(*data.philo[data.i].philo, NULL);
		data.i++;
	}
	free(data.philo[0].philo);
	free(data.philo[1].philo);
	free(data.philo);
	return (0);
}
