/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_simulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:42:07 by jallerha          #+#    #+#             */
/*   Updated: 2022/08/18 11:01:42 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_init_philo(int id, t_settings *settings)
{
	t_philo	new;

	ft_bzero(&new, sizeof(t_philo));
	new.id = id + 1;
	new.eaten = 0;
	new.settings = settings;
	new.state = 1;
	settings->philos[id] = new;
	return (0);
}

int	ft_spawn_philos(t_settings *settings)
{
	t_philo	*philo_array;
	int		i;

	i = 0;
	philo_array = (t_philo *) malloc(sizeof(t_philo) * settings->n_philos);
	if (!philo_array)
		return (-1);
	ft_bzero(philo_array, sizeof(t_philo) * settings->n_philos);
	settings->philos = philo_array;
	while (i < settings->n_philos)
	{
		if (ft_init_philo(i, settings) < 0)
			return (-1);
		i++;
	}
}

int	ft_init_simulation(t_settings *settings)
{
	if (ft_spawn_philos(settings) == -1)
		return (ft_error("Error while spawning philosophers", -1));
	if (ft_create_forks(settings->n_philos, settings) == -1)
		return (ft_error("Error creating forks", -1));
	if (ft_misc_mutexes(settings) == -1)
		return (ft_error("Error creating mutexes", -1));
	ft_select_forks(settings->philos, settings);
}
