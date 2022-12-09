/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:56:14 by beatriz           #+#    #+#             */
/*   Updated: 2022/12/09 23:31:12 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static int	check_args(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if ((argc < 5) || (argc > 6))
		return (print_message_error("error: needed 5 or 6 arguments"));
	while (argv[++i])
	{
		if ((argv[i][j] == '+') && (argv[i][j + 1] != '\0'))
				j++;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == FALSE)
				return (print_message_error("error: put (positive) numbers"));
			j++;
		}
		if ((ft_strlen(argv[i]) > 10) || (ft_atol(argv[i]) > __INT_MAX__))
			return (print_message_error("error: number(s) exceed MAX_INT"));
		if (ft_atol(argv[i]) < 1)
			return (print_message_error("error: Put values greater than 0"));
		j = 0;
	}
	return (TRUE);
}

static void	init_data(int argc, char *argv[], t_data *data)
{
	data->n_philos = ft_atol(argv[1]);
	data->time_to_die = ft_atol(argv[2]);
	data->time_to_eat = ft_atol(argv[3]);
	data->time_to_sleep = ft_atol(argv[4]);
	data->n_times_eat = LIMITLESS;
	if (argc == 6)
		data->n_times_eat = ft_atol(argv[5]);
	data->die = FALSE;
}

static int	init_philo(t_data *data)
{
	int	i;

	i = 0;
	data->philo_index = ft_calloc(data->n_philos, sizeof(t_philo));
	if (data->philo_index == NULL)
		return (print_message_error("error: init_philo allocation"));
	while (i < data->n_philos)
	{
		data->philo_index[i].id = i + 1;
		data->philo_index[i].times_ate = data->n_times_eat;
		if (i == 0)
			data->philo_index[i].fork_left = data->n_philos - 1;
		else
			data->philo_index[i].fork_left = i - 1;
		data->philo_index[i].fork_right = i;
		data->philo_index[i].data = data;
		i++;
	}
	return (TRUE);
}

static int	init_mutexes(t_data *data)
{
	int	i;

	i = -1;
	data->forks = ft_calloc(data->n_philos, sizeof(pthread_mutex_t));
	if (data->forks == NULL)
		return (print_message_error("error: init_forks allocation"));
	data->time_to_die_cur = ft_calloc(data->n_philos, sizeof(pthread_mutex_t));
	if (data->time_to_die_cur == NULL)
		return (print_message_error("error: init_forks allocation"));
	data->times_ate = ft_calloc(data->n_philos, sizeof(pthread_mutex_t));
	if (data->times_ate == NULL)
		return (print_message_error("error: init_forks allocation"));
	while (++i < data->n_philos)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		pthread_mutex_init(&data->time_to_die_cur[i], NULL);
		pthread_mutex_init(&data->times_ate[i], NULL);
	}
	pthread_mutex_init(&data->status_msg, NULL);
	pthread_mutex_init(&data->die_mutex, NULL);
	return (TRUE);
}

int	init(int argc, char *argv[], t_data *data)
{
	data->philo_index = NULL;
	data->forks = NULL;
	if (check_args(argc, argv) != TRUE)
		return (FALSE);
	init_data(argc, argv, data);
	if (init_philo(data) != TRUE)
		return (FALSE);
	if (init_mutexes(data) != TRUE)
		return (FALSE);
	return (TRUE);
}
