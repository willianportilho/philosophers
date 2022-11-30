/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:46:27 by wportilh          #+#    #+#             */
/*   Updated: 2022/11/30 03:28:35 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

long long current_time(void)
{
    struct timeval  time;

    gettimeofday(&time, NULL);
    return ((time.tv_usec / 1000) + (time.tv_sec * 1000));
}
