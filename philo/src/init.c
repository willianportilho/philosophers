/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:56:14 by beatriz           #+#    #+#             */
/*   Updated: 2022/11/23 14:08:42 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void    init(t_data *data)
{
    int count;

    count = 0;
    data->i = 0;
    data->n_philo = 2;
    data->philo = ft_calloc(2, sizeof(t_philo));
    while(count < data->n_philo)
    {
        data->philo[count].philo = ft_calloc(1, sizeof(pthread_t));
        count++;
    }
}
