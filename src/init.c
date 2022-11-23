/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beatriz <beatriz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:56:14 by beatriz           #+#    #+#             */
/*   Updated: 2022/11/23 13:40:03 by beatriz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void    init(t_data *data)
{
    data->i = 0;
    data->philo = ft_calloc(2, sizeof(t_philo));
    data->philo[0].philo = ft_calloc(1, sizeof(pthread_t));
    data->philo[1].philo = ft_calloc(1, sizeof(pthread_t));
}
