/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 11:12:53 by jallerha          #+#    #+#             */
/*   Updated: 2022/08/18 11:17:29 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

long long int	ft_timestamp(void)
{
	static long long int	start = 0;
	struct timeval			tv;
	long long int			timestamp;

	if (start == 0)
	{
		gettimeofday(&tv, NULL);
		start = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	}
	gettimeofday(&tv, NULL);
	timestamp = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (timestamp - start);
}