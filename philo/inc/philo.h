/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:37:26 by wportilh          #+#    #+#             */
/*   Updated: 2022/12/03 18:25:03 by wportilh         ###   ########.fr       */
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

# define TRUE 1
# define FALSE 0
# define SUCCESS 0
# define LIMITLESS -1
# define FINISH_EAT 0
# define LAG 1000
# define WAITING 1
# define EATING 2
# define SLEEPING 3

typedef struct s_philo
{
	int				id;
	int				fork_left;
	int				fork_right;
	int				times_ate;
	pthread_t		philo_thread;
	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	int				i;
	int				n_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_times_eat;
	int				*fork_is_lock;
	long long		initial_time;
	pthread_mutex_t	status_msg;
	pthread_mutex_t	*forks;
	t_philo			*philo_index;
}					t_data;

long long	current_time(void);
int			init(int argc, char *argv[], t_data *data);
void		clean(t_data *data);
int			start(t_data *data);
int			finish(t_data *data);
int			print_message_error(char *message);
void		*life_error(char *message);

/* ---------------------------------------------------------------------*\
|	utils																 |
\* ---------------------------------------------------------------------*/
int			ft_isdigit(int c);
size_t		ft_strlen(const char *s);
long		ft_atol(const char *nptr);
void		*ft_memset(void *s, int c, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);

#endif