/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 12:35:04 by jallerha          #+#    #+#             */
/*   Updated: 2022/08/11 16:35:41 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

/**
 * @brief Print the help message
 * 
 * @param bin_name The name of the binary (or path) -- argv[0]
 */
void	ft_print_help(char *bin_name)
{
	ft_putstr_fd("Usage: \n\t", STDERR);
	ft_putstr_fd(bin_name, STDERR);
	ft_putstr_fd(" [options]\n", STDERR);
}
