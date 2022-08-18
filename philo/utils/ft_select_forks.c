/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_forks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:39:52 by jallerha          #+#    #+#             */
/*   Updated: 2022/08/19 00:26:14 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

/**
 * @brief Select forks for philosopher, swaps them to avoid deadlock.
 * 
 * @param philos The philosopher that is eating.
 * @param settings The settings of the simulation.
 */
void	ft_select_forks(t_philo *philos, t_settings *settings)
{
	int				i;
	int				fork_left_index;
	int				fork_right_index;
	int				swap_val;

	i = 0;
	while (i < settings->n_philos)
	{
		fork_left_index = i;
		fork_right_index = i - 1;
		if (fork_right_index < 0)
			fork_right_index = settings->n_philos - 1;
		if (fork_right_index > fork_left_index)
		{
			swap_val = fork_left_index;
			fork_left_index = fork_right_index;
			fork_right_index = swap_val;
		}
		philos[i].left_fork = &settings->forks[fork_left_index];
		philos[i].right_fork = &settings->forks[fork_right_index];
		i++;
	}
}
