/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 00:50:43 by jallerha          #+#    #+#             */
/*   Updated: 2022/08/19 00:57:53 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	micro_sleep(long long duration, t_philo *philo)
{
	int	slices;
	int	per_slice_sleep;

	if (duration < 10000)
	{
		slices = duration / 1000;
		per_slice_sleep = 1000;
	}
	else if (duration < 1000000)
	{
		slices = duration / 10000;
		per_slice_sleep = 10000;
	}
	else
	{
		slices = duration / 1000000;
		per_slice_sleep = 1000000;
	}
	while (slices--)
	{
		usleep(per_slice_sleep);
		if (ft_is_over(philo->settings))
			return (0);
	}
	return (1);
}
