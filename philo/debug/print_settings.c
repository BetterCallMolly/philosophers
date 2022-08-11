/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_settings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:08:33 by jallerha          #+#    #+#             */
/*   Updated: 2022/08/11 16:38:12 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"
#include "../colors.h"

void	ft_print_settings(t_settings *settings)
{
	ft_putstr_fd(LIGHTSKYBLUE2, STDERR);
	ft_putstr_fd("\nSettings:\n", STDERR);
	ft_putstr_fd(RESET, STDERR);
	ft_putstr_fd("\t- Number of philosophers: ", STDERR);
	ft_putnbr_fd(settings->n_philos, STDERR);
	ft_putstr_fd("\n\t- Time to die: ", STDERR);
	ft_putnbr_fd(settings->time_to_die, STDERR);
	ft_putstr_fd("\n\t- Time to eat: ", STDERR);
	ft_putnbr_fd(settings->time_to_eat, STDERR);
	ft_putstr_fd("\n\t- Time to sleep: ", STDERR);
	ft_putnbr_fd(settings->time_to_sleep, STDERR);
	ft_putstr_fd("\n\t- Number of meals: ", STDERR);
	ft_putnbr_fd(settings->n_meals, STDERR);
	ft_putstr_fd("\n\t- Limited meals: ", STDERR);
	ft_putnbr_fd(settings->limited_meals, STDERR);
	ft_putstr_fd("\n\n", STDERR);
}
