/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_misc_mutexes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:45:11 by jallerha          #+#    #+#             */
/*   Updated: 2022/08/15 15:48:11 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

/**
 * @brief Creates additionnal mutexes for the simulation (print // state)
 * if any error occurs, the function cleans up, prints the error and returns -1
 * @param settings Pointer to settings structure
 * @return int -1 if error, otherwise 0
 */
int	ft_misc_mutexes(t_settings *settings)
{
	if (pthread_mutex_init(&settings->print_mutex, NULL))
		return (ft_error("Error creating print_mutex", -1));
	if (pthread_mutex_init(&settings->state_mutex, NULL))
	{
		pthread_mutex_destroy(&settings->print_mutex);
		return (ft_error("Error creating state_mutex", -1));
	}
	return (0);
}
