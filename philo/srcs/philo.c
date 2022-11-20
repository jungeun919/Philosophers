/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:46:05 by jungchoi          #+#    #+#             */
/*   Updated: 2022/11/20 13:02:58 by jungchoi         ###   ########.fr       */
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
	init_info(&info, argv);
	init_philo(&philo, &info);
	start_philo_process(&philo, &info);
	return (0);
}

void	start_philo_process(t_philo **philo, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_of_philo)
	{
		pthread_create(&((*philo)[i].thread), NULL, routine, &((*philo)[i]));
		i++;
	}
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->start_time = get_time();
	printf("%lld\n", philo->start_time);
	philo->eat_time = get_time();
	if (philo->id % 2 == 0)
		usleep(philo->info->time_to_eat * 1000);
}

long long	get_time(void)
{
	struct timeval	now;
	long long		time;

	gettimeofday(&now, NULL);
	time = now.tv_sec * 1000 + now.tv_usec / 1000;
	return (time);
}

void	error_exit(char *str)
{
	printf("%s\n", str);
	exit(1);
}
