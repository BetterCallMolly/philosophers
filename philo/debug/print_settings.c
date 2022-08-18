/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_settings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:08:33 by jallerha          #+#    #+#             */
/*   Updated: 2022/08/18 11:06:01 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"
#include "../colors.h"

void	ft_print_settings(t_settings *settings)
{
	if (!DEBUG)
		return ;
	printf("%s\nSettings%s\n\t- Number of philosophers : %d" \
	"\n\t- Time to die : %d" \
	"\n\t- Time to eat : %d" \
	"\n\t- Time to sleep : %d" \
	"\n\t- Number of meals : %d" \
	"\n\t- Limited meals : %d%s\n", LIGHTSKYBLUE2, PINK1, settings->n_philos,
		settings->time_to_die, settings->time_to_eat, settings->time_to_sleep,
		settings->n_meals, settings->limited_meals, RESET);
}
