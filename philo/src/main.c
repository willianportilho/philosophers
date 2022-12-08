/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willian <willian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:35:34 by wportilh          #+#    #+#             */
/*   Updated: 2022/12/08 19:13:49 by willian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int argc, char *argv[])
{
	t_data		data;

	if (init(argc, argv, &data) != TRUE)
		return (FALSE);
	if (data.n_philos == 1)
	{
		start_one(&data);
		return (TRUE);
	}	
	if (start(&data) != TRUE)
		return (FALSE);
	if (finish(&data) != TRUE)
		return (FALSE);
	clean(&data);
	return (0);
}
