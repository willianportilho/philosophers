/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:35:34 by wportilh          #+#    #+#             */
/*   Updated: 2022/11/22 23:57:47 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*life(void *teste)
{
	if (!teste)
	{
		printf("Philosopher is eating\n");
		printf("Philosopher is sleeping\n");
		printf("Philosopher is thinking\n");
	}
	return (NULL);
}

int	main(void)
{
	pthread_t	philo;

	pthread_create(&philo, NULL, &life, NULL);
	pthread_join(philo, NULL);
	return (0);
}
