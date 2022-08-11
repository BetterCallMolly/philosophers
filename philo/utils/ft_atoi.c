/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 12:33:25 by jallerha          #+#    #+#             */
/*   Updated: 2022/08/11 13:32:37 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static void	ft_skip_space(const char *s, int *i)
{
	while (s[*i] == ' ' || s[*i] == '\t')
		(*i)++;
}

static void	ft_skip_polarity(const char *s, int *i, int *signe)
{
	if (s[*i] == '+' || s[*i] == '-')
	{
		if (s[*i] == '-')
			(*signe) *= -1;
		(*i)++;
	}
}

static int	ft_full_digit(const char *s, int i)
{
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(const char *s)
{
	int		signe;
	int		i;
	long	n;

	signe = 1;
	i = 0;
	n = 0;
	ft_skip_space(s, &i);
	ft_skip_polarity(s, &i, &signe);
	if (!ft_full_digit(s, i))
		return (-1);
	while (s[i] >= '0' && s[i] <= '9')
	{
		if (n * signe > 2147483647)
			return (-1);
		else if (n * signe < -2147483648)
			return (0);
		n = n * 10 + s[i] - '0';
		i++;
	}
	return (n * signe);
}
