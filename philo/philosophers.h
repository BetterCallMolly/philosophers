/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 12:36:09 by jallerha          #+#    #+#             */
/*   Updated: 2022/08/11 17:02:46 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>

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
	pthread_mutex_t	*forks;
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

// Forks management
int		ft_destroy_forks(int count_init, t_settings *settings);
int		ft_create_forks(int count, t_settings *settings);
void	ft_destroy_simulation(t_settings *settings);

// Misc functions
int		ft_alone(void);

// Debug functions
void	ft_print_settings(t_settings *settings);

#endif