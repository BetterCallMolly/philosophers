/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 12:35:04 by jallerha          #+#    #+#             */
/*   Updated: 2022/08/15 15:37:35 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"
#include "../colors.h"

/**
 * @brief Print the help message
 * 
 * @param bin_name The name of the binary (or path) -- argv[0]
 * @return int 1
 */
int	ft_print_help(char *bin_name)
{
	ft_putstr_fd(RED2, STDERR);
	ft_putstr_fd(ERROR_ARGUMENTS, STDERR);
	ft_putstr_fd(RESET, STDERR);
	ft_putstr_fd(PINK1, STDERR);
	ft_putstr_fd("\nUsage: ", STDERR);
	ft_putstr_fd(bin_name, STDERR);
	ft_putstr_fd(LIGHTCORAL, STDERR);
	ft_putstr_fd(" <n_philosophers> <time_to_eat> <time_to_sleep>" \
		" <time_to_die> ",
		STDERR);
	ft_putstr_fd(GREY78, STDERR);
	ft_putstr_fd("[n_meals]\n", STDERR);
	return (1);
}
