/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:35:34 by wportilh          #+#    #+#             */
/*   Updated: 2022/11/23 04:50:10 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*life(void *philo)
{
	t_philo	*pointer_philo;

	pointer_philo = (t_philo *) philo;
	printf("Philosopher %d is eating\n", pointer_philo->a);
	printf("Philosopher %d is sleeping\n", pointer_philo->a);
	printf("Philosopher %d is thinking\n", pointer_philo->a);
	return (NULL);
}

int	main(void)
{
	t_philo		*philo;
	int			i;

	i = 0;
	philo = malloc(2 * sizeof(t_philo));
	philo[0].philo = malloc(sizeof(pthread_t));
	philo[1].philo = malloc(sizeof(pthread_t));
	while (i < 2)
	{
		philo[i].a = i + 1;
		pthread_create(philo[i].philo, NULL, &life, (void *)philo + i);
		i++;
	}
	i = 0;
	while (i < 2)
	{
		pthread_join(*philo[i].philo, NULL);
		i++;
	}
	free(philo[0].philo);
	free(philo[1].philo);
	free(philo);
	return (0);
}
