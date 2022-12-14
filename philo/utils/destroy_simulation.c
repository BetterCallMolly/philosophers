/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_simulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:58:14 by jallerha          #+#    #+#             */
/*   Updated: 2022/08/19 00:26:46 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

/**
 * @brief Destroy all mutexes and threads cleanly
 * This function asserts that everything is correctly initialized
 * and that the simulation ended properly. (all threads are joined)
 * 
 * @param settings Pointer to settings structure
 */
void	ft_destroy_simulation(t_settings *settings)
{
	ft_destroy_forks(settings->n_philos, settings);
	pthread_mutex_destroy(&settings->print_mutex);
	pthread_mutex_destroy(&settings->state_mutex);
	ft_destroy_meal_mutexes(settings);
	free(settings->threads);
	free(settings->philos);
}
