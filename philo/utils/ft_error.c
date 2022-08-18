/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:50:31 by jallerha          #+#    #+#             */
/*   Updated: 2022/08/17 15:06:10 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"
#include "../colors.h"

int	ft_error(char *message, int return_code)
{
	ft_putstr_fd(RED2, STDERR);
	ft_putstr_fd("ERROR: ", STDERR);
	ft_putstr_fd(message, STDERR);
	ft_putstr_fd(RESET, STDERR);
	ft_putendl_fd("", STDERR);
	return (return_code);
}
