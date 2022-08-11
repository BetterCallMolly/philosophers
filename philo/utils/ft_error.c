/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:50:31 by jallerha          #+#    #+#             */
/*   Updated: 2022/08/11 16:35:37 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_error(char *message, int return_code)
{
	ft_putstr_fd(message, STDERR);
	ft_putendl_fd("", STDERR);
	return (return_code);
}
