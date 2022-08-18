/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 11:31:07 by jallerha          #+#    #+#             */
/*   Updated: 2022/08/18 11:35:05 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"
#include "../colors.h"

void	ft_philo_log(int id, int message, t_settings *settings)
{
	pthread_mutex_lock(&settings->print_mutex);
	if (message == FORK)
		printf("%s%lld %s%d %shas taken a fork%s\n",
			ORANGE1, ft_timestamp(), ORANGE2, id, GREEN1, RESET);
	else if (message == THINK)
		printf("%s%lld %s%d %s is thinking%s\n",
			ORANGE1, ft_timestamp(), ORANGE2, id, GREEN1, RESET);
	else if (message == EAT)
		printf("%s%lld %s%d %s is eating%s\n",
			ORANGE1, ft_timestamp(), ORANGE2, id, GREEN1, RESET);
	else if (message == SLEEP)
		printf("%s%lld %s%d %s is sleeping%s\n",
			ORANGE1, ft_timestamp(), ORANGE2, id, GREEN1, RESET);
	else if (message == DIED)
		printf("%s%lld %s%d %s has died%s\n",
			ORANGE1, ft_timestamp(), ORANGE2, id, RED1, RESET);
}