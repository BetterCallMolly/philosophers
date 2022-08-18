/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_misc_mutexes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:45:11 by jallerha          #+#    #+#             */
/*   Updated: 2022/08/18 22:44:36 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_destroy_meal_mutexes(t_settings *settings)
{
	int	i;

	i = 0;
	while (i < settings->n_philos)
	{
		pthread_mutex_destroy(&settings->philos[i].meal_mutex);
		i++;
	}
}

/**
 * @brief Create meal mutex for every philosopher, destroy in case of error
 * @param settings Pointer to settings structure
 * @return int 0 if success, -1 if error
 */
int	ft_init_meal_mutexes(t_settings *settings)
{
	int	i;

	i = 0;
	while (i < settings->n_philos)
	{
		if (pthread_mutex_init(&settings->philos[i].meal_mutex, NULL))
		{
			while (i >= 0)
			{
				pthread_mutex_destroy(&settings->philos[i].meal_mutex);
				i--;
			}
			return (-1);
		}
		i++;
	}
	return (0);
}

/**
 * @brief Creates additional mutexes for the simulation (print // state)
 * if any error occurs, the function cleans up, prints the error and returns -1
 * @param settings Pointer to settings structure
 * @return int -1 if error, otherwise 0
 */
int	ft_misc_mutexes(t_settings *settings)
{
	if (pthread_mutex_init(&settings->time_mutex, NULL))
		return (ft_error("Error creating time_mutex", -1));
	if (pthread_mutex_init(&settings->print_mutex, NULL))
	{
		pthread_mutex_destroy(&settings->time_mutex);
		return (ft_error("Error creating print_mutex", -1));
	}
	if (pthread_mutex_init(&settings->state_mutex, NULL))
	{
		pthread_mutex_destroy(&settings->time_mutex);
		pthread_mutex_destroy(&settings->print_mutex);
		return (ft_error("Error creating state_mutex", -1));
	}
	return (0);
}
