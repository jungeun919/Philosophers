/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:46:15 by jungchoi          #+#    #+#             */
/*   Updated: 2022/11/26 13:59:12 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_info
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_count;
	long long		start_time;
	int				all_alive;
	pthread_mutex_t	*forks;
	pthread_mutex_t	guard;
	pthread_mutex_t	print;
}	t_info;

typedef struct s_philo
{
	t_info			*info;
	int				id;
	pthread_t		thread;
	pthread_mutex_t	guard;
	int				left_fork;
	int				right_fork;
	long long		eat_time;
	int				eat_count;
	int				is_die;
}	t_philo;

// philo.c
void		start_philo_process(t_philo **philo, t_info *info);
void		*routine(void *arg);

// init.c
int			philo_atoi(const char *str);
void		init_info(t_info *info, int argc, char **argv);
int			check_info_value(t_info *info);
void		init_philo(t_philo **philo, t_info *info);
void		free_info_malloc(t_info *info);

// act.c
void		philo_eat(t_philo *philo);
void		philo_sleep(t_philo *philo);
void		philo_think(t_philo *philo);

// monitor.c
void		monitoring(t_philo **philo, t_info *info);
void		check_philo_die(t_philo *philo, t_info *info);
int			check_all_alive(t_info *info);

// utils.c
void		print_status(t_philo *philo, char *str);
long long	get_time(void);
void		error_exit(char *str);

// free.c
void		free_all(t_philo **philo, t_info *info);

#endif
