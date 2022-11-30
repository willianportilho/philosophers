/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:56:14 by beatriz           #+#    #+#             */
/*   Updated: 2022/11/30 01:44:10 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static int check_args(int argc, char *argv[], t_data *data)
{
    int i;
    int j;

    i = 1;
    j = 0;
    if ((argc < 5) || (argc > 6))
    {
        printf("./philo needed more 4 or 5 arguments\n");
        return (FALSE);
    }
    while (argv[i])
    {
        if ((argv[i][j] == '+') && (argv[i][j + 1] != '\0'))
				j++;
        while (argv[i][j])
        {
            if (ft_isdigit(argv[i][j]) == FALSE)
            {
                printf("Only positive numbers are accept like arguments\n");
                return (FALSE);
            }
            j++;
        }
        j = 0;
        i++;
    }
    data->n_philos = ft_atol(argv[1]);
    return (TRUE);
}

static int init_philo(t_data *data)
{
    data->i = 0;
    data->philo_index = ft_calloc(data->n_philos, sizeof(t_philo));
    if (data->philo_index == NULL)
    {
        printf("init_philo allocation fail\n");
        return (FALSE);
    }
    return (TRUE);
}

static int init_forks(t_data *data)
{
    int i;

    i = 0;
    data->forks = ft_calloc(data->n_philos, sizeof(pthread_mutex_t));
    if (data->forks == NULL)
    {
        printf("init_forks allocation fail\n");
        return (FALSE);
    }
    while (i < data->n_philos)
    {
        if (pthread_mutex_init(&data->forks[i], NULL) == -1)
        {
            printf("forks allocation error\n");
            return (FALSE);
        }
        i++;
    }
    if (pthread_mutex_init(&data->status_msg, NULL) == -1)
    {
        printf("message message allocation error\n");
        return (FALSE);
    }
    return (TRUE);
}

static void init_vars(t_data *data)
{
    int i;

    i = 0;
    while (i < data->n_philos)
    {
        data->philo_index[i].id = i + 1;
        if (i == 0)
            data->philo_index[i].fork_l = data->n_philos - 1;
        else
            data->philo_index[i].fork_l = i - 1;
        data->philo_index[i].fork_r = i;
        data->philo_index[i].data = data;
        i++;
    }
    /*i = -1;
    while (++i < data->n_philos)
        printf("philosopher nº %d: fork_l %d | fork_r %d\n", i + 1, data->philo_index[i].fork_l,  data->philo_index[i].fork_r);
    */
}

int    init(int argc, char *argv[], t_data *data)
{
    if (check_args(argc, argv, data) != TRUE)
        return (FALSE);
    if (init_philo(data) != TRUE)
        return (FALSE);
    if (init_forks(data) != TRUE)
        return (FALSE);
    init_vars(data);
    return (TRUE);
}
