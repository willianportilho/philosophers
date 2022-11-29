/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 05:25:54 by wportilh          #+#    #+#             */
/*   Updated: 2022/11/29 19:44:37 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

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
