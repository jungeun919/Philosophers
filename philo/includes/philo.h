/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:46:15 by jungchoi          #+#    #+#             */
/*   Updated: 2022/11/20 12:51:43 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h> // exit
# include <pthread.h>
# include <sys/time.h> // gettimeofday

typedef struct s_info
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_count;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	int				is_die;
}	t_info;

typedef struct s_philo
{
	t_info			*info;
	int				id;
	pthread_t		thread;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	right_fork;
	long long		start_time;
	long long		eat_time;
	int				eat_count;
}	t_philo;

void		start_philo_process(t_philo **philo, t_info *info);
void		*routine(void *arg);
long long	get_time(void);
void		error_exit(char *str);

int			philo_atoi(const char *str);
void		init_info(t_info *info, char **argv);
void		init_philo(t_philo **philo, t_info *info);

#endif
