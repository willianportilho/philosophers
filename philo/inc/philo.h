/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:37:26 by wportilh          #+#    #+#             */
/*   Updated: 2022/11/30 01:34:56 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>

#define TRUE 1
#define FALSE 0
#define SUCCESS 0

typedef struct	s_philo
{
	int			id;
	int			fork_l;
	int			fork_r;
	pthread_t	philo_thread;
	struct s_data	*data;
}				t_philo;

typedef struct s_data
{
	int				i;
	int				n_philos;
	pthread_mutex_t	status_msg;
	pthread_mutex_t	*forks;
	t_philo			*philo_index;
}					t_data;

long	current_time(void);
int		init(int argc, char *argv[], t_data *data);
void    clean(t_data *data);
int 	start(t_data *data);
int		finish(t_data *data);

/* ---------------------------------------------------------------------*\
|	utils																 |
\* ---------------------------------------------------------------------*/
int		ft_isdigit(int c);
long	ft_atol(const char *nptr);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);

#endif