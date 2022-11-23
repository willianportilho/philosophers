/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:56:43 by beatriz           #+#    #+#             */
/*   Updated: 2022/11/23 14:03:17 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void    clean(t_data *data)
{
    int count;

    count = 0;
    while (count < data->n_philo)
    {
        free(data->philo[count].philo);
        count++;
    }
	free(data->philo);
}
