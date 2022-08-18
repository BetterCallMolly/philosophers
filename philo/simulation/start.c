/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 11:35:34 by jallerha          #+#    #+#             */
/*   Updated: 2022/08/18 23:19:44 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_join_threads(t_settings *settings)
{
	int	i;

	i = 0;
	while (i < settings->n_philos)
	{
		if (pthread_join(settings->threads[i], NULL))
			return (1);
		i++;
	}
	return (0);
}

int	ft_start_philo(t_philo *philo)
{
	pthread_t	thread;

	if (pthread_create(&thread, NULL, &ft_life_cycle, (void *)philo) != 0)
		return (1);
	philo->settings->threads[philo->id - 1] = thread;
	return (0);
}

int	ft_start_simulation(t_settings *settings)
{
	int	i;

	i = 1;
	while (i < settings->n_philos)
	{
		if (ft_start_philo(&settings->philos[i]))
			return (1);
		i += 2;
	}
	i = 0;
	settings->start_timestamp = ft_timestamp();
	while (i < settings->n_philos)
	{
		if (ft_start_philo(&settings->philos[i]))
			return (1);
		i += 2;
	}
	ft_refree(settings);
	ft_join_threads(settings);
	return (0);
}
