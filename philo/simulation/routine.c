/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 11:01:29 by jallerha          #+#    #+#             */
/*   Updated: 2022/08/19 00:59:37 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*ft_life_cycle(void	*philosopher)
{
	t_settings	*settings;
	t_philo		*philo;

	philo = (t_philo *) philosopher;
	settings = philo->settings;
	if (philo->wait)
		usleep(settings->time_to_eat * 1000);
	while (0x88b8)
	{
		if (ft_eat(philo, settings))
			return (NULL);
		if (ft_is_over(settings))
			return (NULL);
		ft_philo_log(philo->id, SLEEP, philo->settings);
		if (settings->time_to_sleep < MICRO_SLEEP_THRESHOLD)
			usleep(settings->time_to_sleep * 1000);
		else
			if (!micro_sleep(settings->time_to_sleep, philo))
				return (NULL);
		if (ft_is_over(philo->settings))
			return (NULL);
		ft_philo_log(philo->id, THINK, philo->settings);
	}
	return (NULL);
}
