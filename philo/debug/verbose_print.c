/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:53:39 by jallerha          #+#    #+#             */
/*   Updated: 2022/08/18 11:01:34 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_verbose(char *message, char *file, int line)
{
	if (!DEBUG)
		return ;
	ft_putstr_fd("[", STDERR);
	ft_putstr_fd(file, STDERR);
	ft_putstr_fd(":", STDERR);
	ft_putnbr_fd(line, STDERR);
	ft_putstr_fd("] ", STDERR);
	ft_putstr_fd(message, STDERR);
}
