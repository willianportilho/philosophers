/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 04:26:45 by wportilh          #+#    #+#             */
/*   Updated: 2022/12/03 20:30:11 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int print_message_error(char *message)
{
    printf("%s\n", message);
    return (FALSE);
}

int life_error(char *message)
{
    printf("%s\n", message);
    return (FALSE);
}
