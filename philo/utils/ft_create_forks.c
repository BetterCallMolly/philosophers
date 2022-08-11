/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_forks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:46:07 by jallerha          #+#    #+#             */
/*   Updated: 2022/08/11 17:04:09 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

/**
 * @brief Free all initialized forks
 * 
 * @param count_init Number of initialized forks
 * @param settings Pointer to settings structure
 * @return int 0 if success, -1 if error
 */
int	ft_destroy_forks(int count_init, t_settings *settings)
{
	int	i;

	i = 0;
	while (i < count_init)
	{
		pthread_mutex_destroy(&settings->forks[i]);
		i++;
	}
	free(settings->forks);
	return (-1);
}

/**
 * @brief Initialize all forks, failure-safe
 * 
 * @param count Number of forks to initialize
 * @param settings Pointer to settings structure
 * @return int -1 if error, otherwise number of initialized forks
 */
int	ft_create_forks(int count, t_settings *settings)
{
	int				i;
	unsigned long	size;

	size = sizeof(pthread_mutex_t) * count;
	i = 0;
	settings->forks = (pthread_mutex_t *) malloc(size);
	if (!settings->forks)
		return (-1);
	while (i < count)
	{
		if (pthread_mutex_init(&settings->forks[i], NULL))
			return (ft_destroy_forks(i, settings));
		i++;
	}
	return (i);
}
