/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:56:06 by jungchoi          #+#    #+#             */
/*   Updated: 2022/12/04 14:57:40 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	get_fork(t_philo *philo)
{
	pthread_mutex_lock(&(philo->info->forks[philo->left_fork]));
	if (check_all_alive(philo->info))
		print_status(philo, "has taken a fork");
	else
		pthread_mutex_unlock(&(philo->info->forks[philo->left_fork]));
	pthread_mutex_lock(&(philo->info->forks[philo->right_fork]));
	if (check_all_alive(philo->info))
		print_status(philo, "has taken a fork");
	else
	{
		pthread_mutex_unlock(&(philo->info->forks[philo->left_fork]));
		pthread_mutex_unlock(&(philo->info->forks[philo->right_fork]));
	}
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&(philo->guard));
	philo->eat_time = get_time();
	pthread_mutex_unlock(&(philo->guard));
	if (check_all_alive(philo->info))
	{
		print_status(philo, "is eating");
		while (1)
		{
			if (get_time() - philo->eat_time >= philo->info->time_to_eat)
				break ;
			else
				usleep(100);
		}
	}
	pthread_mutex_unlock(&(philo->info->forks[philo->left_fork]));
	pthread_mutex_unlock(&(philo->info->forks[philo->right_fork]));
}

void	philo_sleep(t_philo *philo)
{
	long long	sleep_start_time;

	if (check_all_alive(philo->info))
	{
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
}

void	philo_think(t_philo *philo)
{
	if (check_all_alive(philo->info))
		print_status(philo, "is thinking");
}
