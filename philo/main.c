/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 12:31:21 by jallerha          #+#    #+#             */
/*   Updated: 2022/08/15 15:44:57 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_settings	settings;
	int			sanity_flag;

	ft_bzero(&settings, sizeof(t_settings));
	if (!(argc == 5 || argc == 6))
		return (ft_print_help(argv[0]));
	sanity_flag = ft_parse(argc, argv + 1, &settings);
	if (sanity_flag > 0)
		return (ft_lint(sanity_flag, argv, argc, sanity_flag));
	ft_print_settings(&settings);
	// if (settings.n_philos == 1)
	// 	return (ft_alone());
	if (ft_create_forks(settings.n_philos, &settings) == -1)
		return (ft_error("Error creating forks", 2));
	if (ft_misc_mutexes(&settings) == -1)
		return (ft_error("Error creating mutexes", 2));
	ft_destroy_simulation(&settings);
	return (0);
}
