/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 22:19:14 by jallerha          #+#    #+#             */
/*   Updated: 2022/08/18 23:07:41 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_is_over(t_settings *settings)
{
	int	over;

	pthread_mutex_lock(&settings->state_mutex);
	over = settings->simulation_state != 0;
	pthread_mutex_unlock(&settings->state_mutex);
	return (over);
}

int	ft_check_death(t_settings *settings, t_philo *philo, int forks_locked)
{
	int	state;

	pthread_mutex_lock(&settings->state_mutex);
	state = settings->simulation_state;
	pthread_mutex_unlock(&settings->state_mutex);
	if (state != 0)
	{
		if (forks_locked)
		{
			pthread_mutex_unlock(philo->left_fork);
			pthread_mutex_unlock(philo->right_fork);
		}
		return (1);
	}
	return (0);
}
