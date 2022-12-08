/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willian <willian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:35:34 by wportilh          #+#    #+#             */
/*   Updated: 2022/12/08 16:34:09 by willian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int argc, char *argv[])
{
	t_data		data;

	if (init(argc, argv, &data) != TRUE)
	{
		clean(&data);
		return (FALSE);
	}
	if (start(&data) != TRUE)
	{
		clean(&data);
		return (FALSE);
	}
	finish(&data);
	clean(&data);
	return (0);
}
