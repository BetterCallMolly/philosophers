/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refree.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 20:02:27 by jallerha          #+#    #+#             */
/*   Updated: 2022/08/19 00:45:47 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->settings->time_mutex);
	pthread_mutex_lock(&philo->settings->state_mutex);
	if (ft_timestamp() - philo->last_meal > philo->settings->time_to_die)
	{
		philo->settings->simulation_state = 1;
		pthread_mutex_unlock(&philo->settings->time_mutex);
		pthread_mutex_unlock(&philo->settings->state_mutex);
		ft_philo_log(philo->id, DIED, philo->settings);
		return (1);
	}
	pthread_mutex_unlock(&philo->settings->time_mutex);
	pthread_mutex_unlock(&philo->settings->state_mutex);
	return (0);
}

/**
 * @brief Check whether a philosopher died, or if there's no spaghetti left
 * 
 * @param settings Pointer to settings structure
 */
void	ft_refree(t_settings *settings)
{
	int		i;
	int		no_spaghettis;

	while (0x1337)
	{
		i = 0;
		no_spaghettis = 0;
		while (i < settings->n_philos)
		{
			pthread_mutex_lock(&settings->philos[i].meal_mutex);
			if (settings->limited_meals && settings->philos[i].eaten
				>= settings->n_meals)
				no_spaghettis++;
			ft_is_dead(&settings->philos[i]);
			pthread_mutex_unlock(&settings->philos[i].meal_mutex);
			pthread_mutex_lock(&settings->state_mutex);
			if (settings->simulation_state == 1)
			{
				pthread_mutex_unlock(&settings->state_mutex);
				return ;
			}
			pthread_mutex_unlock(&settings->philos[i].settings->state_mutex);
			i++;
		}
		if (no_spaghettis == settings->n_philos)
			return ;
	}
}
