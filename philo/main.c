/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 12:31:21 by jallerha          #+#    #+#             */
/*   Updated: 2022/08/11 16:36:44 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_settings	settings;
	int			sanity_flag;

	ft_bzero(&settings, sizeof(t_settings));
	if (!(argc == 5 || argc == 6))
		return (ft_error(ERROR_ARGUMENTS, 2));
	sanity_flag = ft_parse(argc, argv + 1, &settings);
	ft_print_settings(&settings);
	if (sanity_flag > 0)
		return (ft_lint(sanity_flag, argv, argc, sanity_flag));
	return (0);
}
