/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:58:40 by jallerha          #+#    #+#             */
/*   Updated: 2022/08/11 16:35:44 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"
#include "../colors.h"

/**
 * @brief Print the command name (argv[0]) in a fancy way
 * 
 * @param s Command name
 * @param last True if it is the last argument. False otherwise
 */
void	ft_print_name(char *s, int last)
{
	ft_putstr_fd(BLUE3, STDERR);
	ft_putstr_fd(s, STDERR);
	ft_putstr_fd(RESET, STDERR);
	ft_putstr_fd(" ", STDERR);
}

/**
 * @brief Print a non-faulty argument in a fancy way
 * 
 * @param s argv[n]
 * @param last True if it is the last argument. False otherwise
 */
void	ft_print_okay(char *s, int last)
{
	ft_putstr_fd(GREEN2, STDERR);
	ft_putstr_fd(s, STDERR);
	ft_putstr_fd(RESET, STDERR);
	if (!last)
		ft_putstr_fd(" ", STDERR);
}

/**
 * @brief Print a faulty argument in a fancy way
 * 
 * @param s argv[n]
 * @param last True if it is the last argument. False otherwise
 */
void	ft_print_faulty(char *s, int last)
{
	ft_putstr_fd(RED2, STDERR);
	ft_putstr_fd(s, STDERR);
	ft_putstr_fd(RESET, STDERR);
	if (!last)
		ft_putstr_fd(" ", STDERR);
}

/**
 * @brief Print a pretty version of the command executed by the user, with
 * errors highlighted using ANSI escape sequences.
 * 
 * @param faulty_mask The mask of the faulty argument.
 * @param argv The array of arguments.
 * @param argc The number of arguments.
 * @param return_code The return code of the command.
 * @return int An integer representing the status code (= return_code).
 */
int	ft_lint(int faulty_mask, char **argv, int argc, int return_code)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (i == 0)
			ft_print_name(argv[i], i == argc - 1);
		else if (faulty_mask & (1 << i - 1))
			ft_print_faulty(argv[i], i == argc - 1);
		else
			ft_print_okay(argv[i], i == argc - 1);
		i++;
	}
	return (return_code);
}
