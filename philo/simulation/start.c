/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 11:35:34 by jallerha          #+#    #+#             */
/*   Updated: 2022/08/19 13:08:02 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_join_threads(t_settings *settings, int panic)
{
	int	i;

	i = 0;
	if (!panic)
	{
		while (i < settings->n_philos)
		{
			if (pthread_join(settings->threads[i], NULL))
				return (1);
			i++;
		}
	}
	else
	{
		while (i < settings->n_philos)
		{
			if (settings->threads[i]
				&& pthread_join(settings->threads[i], NULL))
				return (1);
			i++;
		}
	}
	return (0);
}

void	ft_handle_thread_error(t_settings *settings)
{
	ft_error("Failed to initialize simulation properly. Panic exiting", -1);
	ft_set_state(settings, 0x42);
	ft_error("Waiting for threads to end.", -1);
	ft_join_threads(settings, 1);
	ft_error("Destroying simulation", -1);
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
	settings->start_timestamp = ft_timestamp();
	while (i < settings->n_philos)
	{
		if (ft_start_philo(&settings->philos[i]))
		{
			ft_handle_thread_error(settings);
			return (1);
		}
		i += 2;
	}
	i = 0;
	while (i < settings->n_philos)
	{
		if (ft_start_philo(&settings->philos[i]))
		{
			ft_handle_thread_error(settings);
			return (1);
		}
		i += 2;
	}
	ft_refree(settings);
	ft_join_threads(settings, 0);
	return (0);
}
