/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:37:26 by wportilh          #+#    #+#             */
/*   Updated: 2022/12/10 00:03:34 by wportilh         ###   ########.fr       */
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
# define LAG 10000

typedef struct s_philo
{
	int				id;
	int				fork_left;
	int				fork_right;
	int				times_ate;
	long long		time_to_die_cur;
	pthread_t		philo_thread;
	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	int				i;
	int				die;
	int				n_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_times_eat;
	int				check_if_ate;
	long long		initial_time;
	pthread_t		check;
	pthread_mutex_t	die_mutex;
	pthread_mutex_t	status_msg;
	pthread_mutex_t	*time_to_die_cur;
	pthread_mutex_t	*times_ate;
	pthread_mutex_t	*forks;
	t_philo			*philo_index;
}					t_data;

long long	current_time(void);
int			init(int argc, char *argv[], t_data *data);
void		clean(t_data *data);
void		start(t_data *data);
void		finish(t_data *data);
int			print_message_error(char *message);
void		print_status_msg(char *status_msg, t_philo *ph);
int			life_error(char *message);
void		*life(void *philo);
void		*life_one(void *philo);
void		start_one(t_data *data);

/* ---------------------------------------------------------------------*\
|	utils																 |
\* ---------------------------------------------------------------------*/
int			ft_isdigit(int c);
size_t		ft_strlen(const char *s);
long		ft_atol(const char *nptr);
void		*ft_memset(void *s, int c, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);

#endif