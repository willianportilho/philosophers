/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:35:34 by wportilh          #+#    #+#             */
/*   Updated: 2022/11/22 22:59:25 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int main(void)
{
	struct timeval	current_time;
	long	sum;

	sleep(4);
	gettimeofday(&current_time, NULL);
	sum = current_time.tv_sec;
	sum += current_time.tv_usec / 1000 / 1000;
	printf("         tv_sec: %ld\n", current_time.tv_sec);
	printf("        tv_usec: %ld\n", current_time.tv_usec);
	printf("Current time is: %ld\n", sum);
    return (0);
}