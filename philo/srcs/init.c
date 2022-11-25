/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:57:03 by jungchoi          #+#    #+#             */
/*   Updated: 2022/11/25 20:06:04 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	philo_atoi(const char *str)
{
	int			i;
	long long	res;

	i = 0;
	res = 0;
	while ((9 <= str[i] && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			res = (res * 10) + (str[i] - '0');
			if (res > 2147483647)
				error_exit("argument error");
		}
		else
			error_exit("argument error");
		i++;
	}
	return ((int)res);
}

void	init_info(t_info *info, int argc, char **argv)
{
	int	i;

	info->num_of_philo = philo_atoi(argv[1]);
	info->time_to_die = philo_atoi(argv[2]);
	info->time_to_eat = philo_atoi(argv[3]);
	info->time_to_sleep = philo_atoi(argv[4]);
	if (argc == 6)
		info->must_eat_count = philo_atoi(argv[5]);
	else
		info->must_eat_count = -1;
	info->all_alive = 1;
	info->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * info->num_of_philo);
	if (!(info->forks))
		error_exit("malloc error");
	i = 0;
	while (i < info->num_of_philo)
	{
		pthread_mutex_init(&(info->forks[i]), NULL);
		i++;
	}
	pthread_mutex_init(&(info->guard), NULL);
	pthread_mutex_init(&(info->print), NULL);
}

void	init_philo(t_philo **philo, t_info *info)
{
	int	i;

	*philo = malloc(sizeof(t_philo) * info->num_of_philo);
	if (!(*philo))
	{
		// free info
		error_exit("malloc error");
	}
	i = 0;
	while (i < info->num_of_philo)
	{
		(*philo)[i].info = info;
		(*philo)[i].id = i + 1;
		pthread_mutex_init(&((*philo)[i].guard), NULL);
		(*philo)[i].left_fork = i;
		(*philo)[i].right_fork = (i + 1) % info->num_of_philo;
		(*philo)[i].eat_time = 0;
		(*philo)[i].eat_count = 0;
		(*philo)[i].is_die = 0;
		i++;
	}
}
