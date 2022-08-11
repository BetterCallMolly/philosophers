/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 12:44:55 by jallerha          #+#    #+#             */
/*   Updated: 2022/08/11 16:35:51 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

/**
 * @brief Check if any argument has an issue
 * 
 * @param settings A pointer to a struct that contains the settings of
 * the simulation.
 * @return int 0 if success, mask of faulty arguments otherwise.
 */
int	ft_sanity(t_settings *settings)
{
	int	mask;

	mask = 0;
	if (settings->n_philos <= 0)
		mask |= 0b1;
	if (settings->time_to_die <= 0)
		mask |= 0b10;
	if (settings->time_to_eat <= 0)
		mask |= 0b100;
	if (settings->time_to_sleep <= 0)
		mask |= 0b1000;
	if (settings->n_meals < 0 && settings->limited_meals)
		mask |= 0b10000;
	return (mask);
}

/**
 * @brief Parse arguments passed to the program.
 * 
 * @param argc Number of arguments passed to the program.
 * @param argv Array of arguments passed to the program.
 * @param settings A pointer to a struct that contains the settings of
 * the simulation.
 * @return int 0 if success, mask of faulty arguments otherwise.
 */
int	ft_parse(int argc, char **argv, t_settings *settings)
{
	settings->n_philos = ft_atoi(argv[0]);
	settings->time_to_die = ft_atoi(argv[1]);
	settings->time_to_eat = ft_atoi(argv[2]);
	settings->time_to_sleep = ft_atoi(argv[3]);
	if (argc == 6)
		settings->n_meals = ft_atoi(argv[4]);
	else
		settings->n_meals = -1;
	settings->limited_meals = argc == 6;
	return (ft_sanity(settings));
}

// argv[0] = number_of_philosophers
// argv[1] = time_to_die
// argv[2] = time_to_eat
// argv[3] = time_to_sleep
// ?argv[4] = number_of_time_each_philosopher_must_eat