/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 01:48:22 by wportilh          #+#    #+#             */
/*   Updated: 2022/12/10 01:48:43 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*life_one(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *) philo;
	ph->time_to_die_cur = ph->data->initial_time + ph->data->time_to_die;
	pthread_mutex_lock(&ph->data->forks[ph->fork_right]);
	print_status_msg("has taken a fork", ph);
	while (1)
	{
		if (ph->time_to_die_cur < current_time())
		{
			pthread_mutex_unlock(&ph->data->forks[ph->fork_right]);
			print_status_msg("die", ph);
			return (NULL);
		}
	}
	return (NULL);
}
