/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 11:12:53 by jallerha          #+#    #+#             */
/*   Updated: 2022/08/19 00:38:17 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

long long	ft_timestamp(void)
{
	struct timeval	tv;
	long long		timestamp_ms;

	gettimeofday(&tv, NULL);
	timestamp_ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (timestamp_ms);
}
