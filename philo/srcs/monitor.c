/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:45:26 by jungchoi          #+#    #+#             */
/*   Updated: 2022/11/23 18:46:32 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	monitoring(t_philo **philo, t_info *info)
{
	// eat_count == must_eat_count
	// get_time - eat_time >= time_to_die
}

void	print_status(t_philo *philo, char *str)
{
	pthread_mutex_lock(&(philo->info->print));
	printf("%lld %d %s\n", \
		get_time() - philo->start_time, philo->id, str);
	pthread_mutex_unlock(&(philo->info->print));
}

void	free_all(t_philo **philo, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_of_philo)
	{
		pthread_join((*philo)[i].thread, NULL);
		pthread_mutex_destroy(&(info->forks[i]));
		i++;
	}
	pthread_mutex_destroy(&(info->print));
	free(&(info->forks));
	free(philo);
}
