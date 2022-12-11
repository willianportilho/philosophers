/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_lib.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 05:25:54 by wportilh          #+#    #+#             */
/*   Updated: 2022/12/11 02:34:41 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

long	ft_atol(const char *nptr)
{
	long	result;
	int		signal;
	int		i;

	signal = 1;
	i = 0;
	while ((nptr[i] == ' ') || (nptr[i] == '\t') || (nptr[i] == '\n')
		|| (nptr[i] == '\r') || (nptr[i] == '\v') || (nptr[i] == '\f'))
		i++;
	if ((nptr[i] == '-') || (nptr[i] == '+'))
	{
		if (nptr[i] == '-')
			signal = -1;
		i++;
	}
	nptr = nptr + i;
	i = 0;
	result = 0;
	while ((nptr[i] != '\0') && ((nptr[i] >= 48) && (nptr[i] <= 57)))
	{
		result = (result * 10) + (nptr[i] - 48);
		i++;
	}
	result = result * signal;
	return (result);
}

int	ft_isdigit(int c)
{
	if (((c >= '0') && (c <= '9')))
	{
		return (2048);
	}
	return (0);
}
