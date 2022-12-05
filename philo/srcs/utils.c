/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:48:32 by jungchoi          #+#    #+#             */
/*   Updated: 2022/12/05 15:19:56 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_status(t_philo *philo, char *str)
{
	pthread_mutex_lock(&(philo->info->guard));
	if (philo->info->all_alive == 0)
	{
		pthread_mutex_unlock(&(philo->info->guard));
		return ;
	}
	pthread_mutex_unlock(&(philo->info->guard));
	pthread_mutex_lock(&(philo->info->print));
	printf("%lld %d %s\n", \
		get_time() - philo->info->start_time, philo->id, str);
	pthread_mutex_unlock(&(philo->info->print));
}

long long	get_time(void)
{
	struct timeval	now;
	long long		time;

	gettimeofday(&now, NULL);
	time = now.tv_sec * 1000 + now.tv_usec / 1000;
	return (time);
}

int	return_error(char *str)
{
	printf("%s\n", str);
	return (0);
}
