/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 19:24:43 by wportilh          #+#    #+#             */
/*   Updated: 2022/12/03 20:57:51 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"


static int	drops_a_fork(t_philo *ph)
{
	if (pthread_mutex_unlock(&ph->data->forks[ph->fork_left]) != SUCCESS)
		return (life_error("error: pthread_mutex_unlock (fork_left)"));
	ph->data->fork_is_lock[ph->fork_left] = FALSE;
	if (pthread_mutex_unlock(&ph->data->forks[ph->fork_right]) != SUCCESS)
		return (life_error("error: pthread_mutex_unlock (fork_right)"));
	ph->data->fork_is_lock[ph->fork_right] = FALSE;
	return (TRUE);
}
static void	check_if_is_dead(int status, t_philo *ph)
{
	if (pthread_mutex_lock(&ph->data->die) != SUCCESS)
		return;// (life_error("error: pthread_mutex_lock (die)"));
	if (ph->data->dead == TRUE)
		return;
	if ((status == WAITING) && (ph->time_to_die_cur <= current_time()))
	{
		ph->data->dead = TRUE;
		print_status_msg("dead", ph);
	}
	else if ((status == EATING) &&\
		(ph->time_to_die_cur <= (current_time() + ph->data->time_to_eat)))
	{
		usleep((ph->time_to_die_cur - current_time()) * 1000);
		ph->data->dead = TRUE;
		print_status_msg("dead eat", ph);
	}
	else if ((status == SLEEPING) && \
		(ph->time_to_die_cur <= (current_time() + ph->data->time_to_sleep)))
	{
		usleep((ph->time_to_die_cur - current_time()) * 1000);
		ph->data->dead = TRUE;
		print_status_msg("dead sleep", ph);
	}
	if (pthread_mutex_unlock(&ph->data->die) != SUCCESS)
		return;// (life_error("error: pthread_mutex_unlock (die)"));
}

static int  takes_a_fork(int index, pthread_mutex_t *fork , t_philo *ph)
{
    while (ph->data->fork_is_lock[index] == TRUE)
	{
		check_if_is_dead(WAITING, ph);
		if (ph->data->dead == TRUE)
			return (FALSE);
	}
	if (pthread_mutex_lock(fork) != SUCCESS)
		return (life_error("error: pthread_mutex_lock"));
	if (ph->data->dead == TRUE)
			return (FALSE);
	print_status_msg("has taken a fork", ph);
	ph->data->fork_is_lock[index] = TRUE;
    return (TRUE);
}

void	*life(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *) philo;
	ph->time_to_die_cur = ph->data->initial_time + ph->data->time_to_die;
	while (ph->times_ate != FINISH_EAT)
	{
        if (takes_a_fork(ph->fork_left, &ph->data->forks[ph->fork_left], ph) != TRUE)
            return (NULL);
        if (takes_a_fork(ph->fork_right, &ph->data->forks[ph->fork_right], ph) != TRUE)
            return (NULL);
		print_status_msg("is eating", ph);
		check_if_is_dead(EATING, ph);
		if (ph->data->dead == TRUE)
			return (NULL);
		usleep((ph->data->time_to_eat * 1000));
		ph->time_to_die_cur = current_time() + ph->data->time_to_die;
		drops_a_fork(ph);
		if (--ph->times_ate == 0)
			return (NULL);
		print_status_msg("is sleeping", ph);
		check_if_is_dead(SLEEPING, ph);
		if (ph->data->dead == TRUE)
				return (NULL);
		usleep(ph->data->time_to_sleep * 1000);
		if (ph->data->dead == TRUE)
				return (NULL);
		print_status_msg("is thinking", ph);
	}
	return (NULL);
}
