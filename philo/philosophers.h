/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 12:36:09 by jallerha          #+#    #+#             */
/*   Updated: 2022/08/11 16:36:15 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <unistd.h>
# include <pthread.h>

# define STDOUT 1
# define STDERR 2
# define ERROR_ARGUMENTS "Invalid number of arguments"

// n_meals is negative if not specified
typedef struct s_settings
{
	int				n_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_meals;
	int				limited_meals;
	pthread_mutex_t	*start;
}	t_settings;

int		ft_putstr_fd(char *string, int fd);
int		ft_putnbr_fd(int n, int fd);
int		ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
int		ft_strlen(char *s);
int		ft_atoi(const char *s);
void	ft_bzero(void *s, size_t n);

int		ft_error(char *message, int return_code);
int		ft_parse(int argc, char **argv, t_settings *settings);
int		ft_lint(int faulty_index, char **argv, int argc, int return_code);
// Debug functions
void	ft_print_settings(t_settings *settings);

#endif