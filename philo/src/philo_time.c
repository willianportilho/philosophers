/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:46:27 by wportilh          #+#    #+#             */
/*   Updated: 2022/11/23 16:27:11 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

long current_time(void)
{
    struct timeval  time;

    gettimeofday(&time, NULL);
    return (time.tv_usec / 1000);
}
