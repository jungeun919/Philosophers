/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:45:26 by jungchoi          #+#    #+#             */
/*   Updated: 2022/12/05 20:21:27 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	monitoring(t_philo **philo, t_info *info)
{
	int	i;
	int	count;

	while (check_all_alive(info))
	{
		i = 0;
		count = 0;
		while (i < info->num_of_philo && check_all_alive(info))
		{
			check_philo_die(&((*philo)[i]), info);
			pthread_mutex_lock(&((*philo)[i].guard));
			if ((*philo)[i].finish == 1)
				count++;
			pthread_mutex_unlock(&((*philo)[i].guard));
			i++;
		}
		if (count == info->num_of_philo)
		{
			pthread_mutex_lock(&(info->guard));
			info->all_alive = 0;
			pthread_mutex_unlock(&(info->guard));
		}
	}
}

void	check_philo_die(t_philo *philo, t_info *info)
{
	pthread_mutex_lock(&(philo->guard));
	if (philo->finish == 0)
	{
		if (get_time() - philo->eat_time >= philo->info->time_to_die)
		{
			print_status(philo, "is died");
			pthread_mutex_lock(&(info->guard));
			info->all_alive = 0;
			pthread_mutex_unlock(&(info->guard));
		}
	}
	pthread_mutex_unlock(&(philo->guard));
}

int	check_all_alive(t_info *info)
{
	pthread_mutex_lock(&(info->guard));
	if (info->all_alive == 0)
	{
		pthread_mutex_unlock(&(info->guard));
		return (0);
	}
	else
	{
		pthread_mutex_unlock(&(info->guard));
		return (1);
	}
}
