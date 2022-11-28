/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:46:05 by jungchoi          #+#    #+#             */
/*   Updated: 2022/11/28 18:51:42 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char *argv[])
{
	t_info	info;
	t_philo	*philo;

	if (!(argc == 5 || argc == 6))
		return (return_error("argument error"));
	if (!(init_info(&info, argc, argv)))
		return (0);
	if (!(init_philo(&philo, &info)))
		return (0);
	start_philo_process(&philo, &info);
	free_all(&philo, &info);
	return (0);
}

void	start_philo_process(t_philo **philo, t_info *info)
{
	int	i;

	i = 0;
	info->start_time = get_time();
	while (i < info->num_of_philo)
	{
		pthread_create(&((*philo)[i].thread), NULL, routine, &((*philo)[i]));
		i++;
	}
	if (info->num_of_philo == 1)
	{
		printf("%d %d has taken a fork\n", 0, 1);
		usleep(info->time_to_die * 1000);
		printf("%lld %d is died\n", \
			get_time() - info->start_time, 1);
		return ;
	}
	monitoring(philo, info);
	i = 0;
	while (i < info->num_of_philo)
	{
		pthread_join((*philo)[i].thread, NULL);
		i++;
	}
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(200);
		// usleep(philo->info->time_to_eat * 1000);
	while (check_all_alive(philo->info))
	{
		philo_eat(philo);
		(philo->eat_count)++;
		if (philo->eat_count == philo->info->must_eat_count)
		{
			pthread_mutex_lock(&(philo->guard));
			philo->is_die = 1;
			pthread_mutex_unlock(&(philo->guard));
		}
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}
