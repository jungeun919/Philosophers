/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:46:05 by jungchoi          #+#    #+#             */
/*   Updated: 2022/11/25 21:30:39 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char *argv[])
{
	t_info	info;
	t_philo	*philo;

	if (!(argc == 5 || argc == 6))
	{
		printf("argument error\n");
		exit(1);
	}
	init_info(&info, argc, argv);
	if (info.num_of_philo == 1)
	{
		// pthread_create();
		printf("%d %d has taken a fork\n", 0, 1);
		usleep(info.time_to_die * 1000);
		printf("%d %d is died\n", info.time_to_die, 1);
		return (0);
	}
	init_philo(&philo, &info);
	printf("ms id act\n");
	printf("=========\n");
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
		usleep(1000);
		i++;
	}
	monitoring(philo, info); // main thread
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
	if (philo->id % 2 == 0) // 홀수부터 시작
		usleep(philo->info->time_to_eat);
	while (check_all_alive(philo->info))
	{
		philo_eat(philo);

		pthread_mutex_lock(&(philo->guard));
		philo->eat_count++;
		// printf("========== philo[%d] eat count : %d\n", philo->id, philo->eat_count);
		pthread_mutex_unlock(&(philo->guard));
		
		if (philo->eat_count == philo->info->must_eat_count)
		{
			pthread_mutex_lock(&(philo->guard));
			philo->is_die = 1;
			pthread_mutex_unlock(&(philo->guard));
			break ;
		}
		
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}
