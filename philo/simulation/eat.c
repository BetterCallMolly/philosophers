/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 22:17:15 by jallerha          #+#    #+#             */
/*   Updated: 2022/08/19 00:45:04 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

/**
 * @brief Lock each fork and check if the simulation is over, if so mutexes
 *  are unlocked cleanly.
 * @param philo The philosopher that is eating.
 * @return int 0 if the simulation is over, 1 otherwise.
 */
int	lock_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	if (ft_is_over(philo->settings))
	{
		pthread_mutex_unlock(philo->left_fork);
		return (0);
	}
	ft_philo_log(philo->id, FORK, philo->settings);
	pthread_mutex_lock(philo->right_fork);
	if (ft_is_over(philo->settings))
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return (0);
	}
	ft_philo_log(philo->id, FORK, philo->settings);
	return (1);
}

int	ft_eat(t_philo *philo, t_settings *settings)
{
	if (philo->left_fork == philo->right_fork)
	{
		ft_philo_log(philo->id, FORK, settings);
		usleep(settings->time_to_die * 1000);
		return (1);
	}
	if (!lock_forks(philo))
		return (1);
	ft_philo_log(philo->id, EAT, philo->settings);
	usleep(settings->time_to_eat * 1000);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	if (ft_is_over(philo->settings))
		return (1);
	pthread_mutex_lock(&philo->meal_mutex);
	philo->eaten++;
	pthread_mutex_unlock(&philo->meal_mutex);
	pthread_mutex_lock(&philo->settings->time_mutex);
	philo->last_meal = ft_timestamp();
	pthread_mutex_unlock(&philo->settings->time_mutex);
	return (0);
}
