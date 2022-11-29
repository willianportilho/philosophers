/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:56:14 by beatriz           #+#    #+#             */
/*   Updated: 2022/11/29 15:26:14 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void init_philo(t_data *data)
{
    int count;

    count = 0;
    data->i = 0;
    data->n_philo = 4;
    data->philo = ft_calloc(data->n_philo, sizeof(t_philo));
    while(count < data->n_philo)
    {
        data->philo[count].philo = ft_calloc(1, sizeof(pthread_t));
        count++;
    }    
}

static void init_vars(t_data *data)
{
    int i;

    i = 0;
    while (i < data->n_philo)
    {
        data->philo[i].id = i + 1;
        if (i == 0)
            data->philo[i].fork_l = data->n_philo;
        else
            data->philo[i].fork_l = i;
        data->philo[i].fork_r = i + 1;
        data->philo[i].data = data;
        i++;
    }
    i = -1;
    while (++i < data->n_philo)
        printf("philosopher nº %d: fork_l %d | fork_r %d\n", i + 1, data->philo[i].fork_l,  data->philo[i].fork_r);
}

void    init(t_data *data)
{
    init_philo(data);
    init_vars(data);
}
