/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:56:06 by jungchoi          #+#    #+#             */
/*   Updated: 2022/12/05 15:07:55 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	get_fork(t_philo *philo)
{
	pthread_mutex_lock(&(philo->info->forks[philo->left_fork]));
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(&(philo->info->forks[philo->right_fork]));
	print_status(philo, "has taken a fork");
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&(philo->guard));
	philo->eat_time = get_time();
	pthread_mutex_unlock(&(philo->guard));
	print_status(philo, "is eating");
	while (1)
	{
		if (get_time() - philo->eat_time >= philo->info->time_to_eat)
			break ;
		else
			usleep(100);
	}
	pthread_mutex_unlock(&(philo->info->forks[philo->left_fork]));
	pthread_mutex_unlock(&(philo->info->forks[philo->right_fork]));
}

void	philo_sleep(t_philo *philo)
{
	long long	sleep_start_time;

	sleep_start_time = get_time();
	print_status(philo, "is sleeping");
	while (1)
	{
		if (get_time() - sleep_start_time >= philo->info->time_to_sleep)
			break ;
		else
			usleep(100);
	}
}

void	philo_think(t_philo *philo)
{
	print_status(philo, "is thinking");
}
