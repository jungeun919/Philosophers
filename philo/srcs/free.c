/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:49:27 by jungchoi          #+#    #+#             */
/*   Updated: 2022/12/01 12:45:06 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	free_all(t_philo **philo, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_of_philo)
	{
		pthread_mutex_destroy(&(info->forks[i]));
		pthread_mutex_destroy(&((*philo)[i].guard));
		i++;
	}
	pthread_mutex_destroy(&(info->guard));
	pthread_mutex_destroy(&(info->print));
	free(info->forks);
	free(*philo);
}
