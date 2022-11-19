/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:46:05 by jungchoi          #+#    #+#             */
/*   Updated: 2022/11/19 16:07:58 by jungchoi         ###   ########.fr       */
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
	return (0);
}

void	error_exit(char *str)
{
	printf("%s\n", str);
	exit(1);
}
