/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 05:25:54 by wportilh          #+#    #+#             */
/*   Updated: 2022/11/30 02:11:52 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

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

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*n;

	n = malloc(nmemb * size);
	if (!n)
		return (NULL);
	ft_memset(n, 0, nmemb * size);
	return (n);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (ptr);
}
