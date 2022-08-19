/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_simulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:42:07 by jallerha          #+#    #+#             */
/*   Updated: 2022/08/19 12:50:44 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

t_philo	ft_init_philo(int id, t_settings *settings)
{
	t_philo	new;

	ft_bzero(&new, sizeof(t_philo));
	new.id = id + 1;
	new.eaten = 0;
	new.settings = settings;
	new.state = 1;
	new.wait = id % 2;
	new.last_meal = ft_timestamp();
	settings->philos[id] = new;
	return (new);
}

int	ft_spawn_philos(t_settings *settings)
{
	int		i;

	i = 0;
	settings->philos = (t_philo *) malloc(sizeof(t_philo) * settings->n_philos);
	if (!settings->philos)
		return (-1);
	ft_bzero(settings->philos, sizeof(t_philo) * settings->n_philos);
	while (i < settings->n_philos)
	{
		settings->philos[i] = ft_init_philo(i, settings);
		i++;
	}
	return (0);
}

int	ft_init_simulation(t_settings *settings)
{
	unsigned long	size;

	size = sizeof(pthread_t) * settings->n_philos;
	settings->threads = (pthread_t *) malloc(size);
	ft_bzero(settings->threads, size);
	if (ft_spawn_philos(settings) == -1)
		return (ft_error("Error while spawning philosophers", -1));
	if (ft_create_forks(settings->n_philos, settings) == -1)
		return (ft_error("Error creating forks", -1));
	if (ft_misc_mutexes(settings) == -1)
		return (ft_error("Error creating mutexes", -1));
	ft_select_forks(settings->philos, settings);
	return (0);
}
