/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_settings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:08:33 by jallerha          #+#    #+#             */
/*   Updated: 2022/08/19 12:27:35 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"
#include "../colors.h"

void	ft_print_settings(t_settings *settings)
{
	if (!DEBUG)
		return ;
	printf("%s\nSettings%s\n\t- Number of philosophers : %lld" \
	"\n\t- Time to die : %lld" \
	"\n\t- Time to eat : %lld" \
	"\n\t- Time to sleep : %lld" \
	"\n\t- Number of meals : %lld" \
	"\n\t- Limited meals : %d%s\n", LIGHTSKYBLUE2, PINK1, settings->n_philos,
		settings->time_to_die, settings->time_to_eat, settings->time_to_sleep,
		settings->n_meals, settings->limited_meals, RESET);
}
