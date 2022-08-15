/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_forks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:39:52 by jallerha          #+#    #+#             */
/*   Updated: 2022/08/15 16:44:59 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_select_forks(t_philo *philos, t_settings *settings)
{
	int	i;

	i = 0;
	while (i < settings->n_philos)
	{
		if (i == 0)
		{
			philos[i].left_fork = &settings->forks[settings->n_philos - 1];
			philos[i].right_fork = &settings->forks[i];
		}
		else if (i == settings->n_philos - 1)
		{
			philos[i].left_fork = &settings->forks[i - 1];
			philos[i].right_fork = &settings->forks[0];
		}
		else
		{
			philos[i].left_fork = &settings->forks[i - 1];
			philos[i].right_fork = &settings->forks[i];
		}
		i++;
	}
}