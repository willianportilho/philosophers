/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:56:43 by beatriz           #+#    #+#             */
/*   Updated: 2022/11/25 20:54:52 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void    clean(t_data *data)
{
    int i;

    i = 0;
    while (i < data->n_philo)
    {
        free(data->philo[i].philo);
        i++;
    }
	free(data->philo);
}
