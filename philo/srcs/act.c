/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:56:06 by jungchoi          #+#    #+#             */
/*   Updated: 2022/11/23 18:02:34 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&(philo->info->forks[philo->left_fork]));
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(&(philo->info->forks[philo->right_fork]));
	print_status(philo, "has taken a fork");
	print_status(philo, "is eating");
	while (philo->info->all_alive == 1)
	{
		if (get_time() - philo->eat_time >= philo->info->time_to_eat)
			usleep(100);
	}
	philo->eat_count++;
	if (philo->eat_count == philo->info->must_eat_count)
		philo->info->finish = 1;
	pthread_mutex_unlock(&(philo->info->forks[philo->right_fork]));
	pthread_mutex_unlock(&(philo->info->forks[philo->left_fork]));
}

void	philo_sleep(t_philo *philo)
{
	long long	sleep_start_time;

	if (philo->info->all_alive == 1)
	{
		sleep_start_time = get_time();
		print_status(philo, "is sleeping");
		while (1)
		{
			if (get_time() - sleep_start_time >= philo->info->time_to_sleep)
				usleep(100);
		}
	}
}

void	philo_think(t_philo *philo)
{
	if (philo->info->all_alive == 1)
		print_status(philo, "is thinking");
}
