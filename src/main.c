/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:35:34 by wportilh          #+#    #+#             */
/*   Updated: 2022/11/23 00:24:04 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*life(void *teste)
{
	printf("Philosopher %d is eating\n", *(int *)teste);
	printf("Philosopher %d is sleeping\n", *(int *)teste);
	printf("Philosopher %d is thinking\n", *(int *)teste);
	free(teste);
	return (NULL);
}

int	main(void)
{
	pthread_t	philo[2];
	int			*a;
	int			i;

	i = 0;
	while (i < 2)
	{
		a = malloc(sizeof(int));
		*a = i;
		pthread_create(&philo[i], NULL, &life, a);
		i++;
	}
	i = 0;
	while (i < 2)
	{
		pthread_join(philo[i], NULL);
		i++;
	}
	return (0);
}
