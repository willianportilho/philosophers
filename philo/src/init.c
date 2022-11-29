/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:56:14 by beatriz           #+#    #+#             */
/*   Updated: 2022/11/29 19:55:35 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void check_args(int argc, char *argv[])
{
    int i;
    int j;

    i = 1;
    j = 0;
    if ((argc < 5) || (argc < 6))
        printf("./philo needed more 4 or 5 arguments\n");
    while (argv[i])
    {
        while (argv[i][j])
        {
            if (((ft_isdigit(argv[i][j]) == 0) || (argv[i][j] < 0)) && (argv[i][0] != '+'))
            {
                printf("Only positive numbers are accept like arguments\n");
            }
            j++;
        }
        i++;
    }
}

static void init_philo(t_data *data)
{
    data->i = 0;
    data->n_philo = 4;
    data->philo_index = ft_calloc(data->n_philo, sizeof(t_philo));
}

static void init_forks(t_data *data)
{
    int i;

    i = 0;
    data->forks = ft_calloc(data->n_philo, sizeof(pthread_mutex_t));
    while (i < data->n_philo)
    {
        pthread_mutex_init(&data->forks[i], NULL);
        i++;
    }
    pthread_mutex_init(&data->message, NULL);
}

static void init_vars(t_data *data)
{
    int i;

    i = 0;
    while (i < data->n_philo)
    {
        data->philo_index[i].id = i + 1;
        if (i == 0)
            data->philo_index[i].fork_l = data->n_philo - 1;
        else
            data->philo_index[i].fork_l = i - 1;
        data->philo_index[i].fork_r = i;
        data->philo_index[i].data = data;
        i++;
    }
    /*i = -1;
    while (++i < data->n_philo)
        printf("philosopher nº %d: fork_l %d | fork_r %d\n", i + 1, data->philo_index[i].fork_l,  data->philo_index[i].fork_r);
    */
}

void    init(int argc, char *argv[], t_data *data)
{
    check_args(argc, argv);
    init_philo(data);
    init_forks(data);
    init_vars(data);
}
