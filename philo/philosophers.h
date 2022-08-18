/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 12:36:09 by jallerha          #+#    #+#             */
/*   Updated: 2022/08/18 12:27:47 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <string.h>

# ifndef DEBUG
#  define DEBUG 1
# endif

# define STDOUT 1
# define STDERR 2

# define FORK 10
# define EAT 11
# define SLEEP 12
# define THINK 13
# define DIED 14

# define ERROR_ARGUMENTS "Invalid number of arguments"

// n_meals is negative if not specified
// if simulation_state is not 0, the simulation is over (a philosopher died)

typedef struct s_philo	t_philo;

typedef struct s_settings
{
	int				n_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_meals;
	int				limited_meals;
	int				simulation_state;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	state_mutex;
}	t_settings;

typedef struct s_philo
{
	int				id;
	int				eaten;
	int				state;
	int				wait;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_settings		*settings;
}	t_philo;

int			ft_putstr_fd(char *string, int fd);
int			ft_putnbr_fd(int n, int fd);
int			ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
int			ft_strlen(char *s);
int			ft_atoi(const char *s);
void		ft_bzero(void *s, size_t n);

int			ft_error(char *message, int return_code);

// Parsing functions
int			ft_parse(int argc, char **argv, t_settings *settings);
int			ft_lint(int faulty_index, char **argv, int argc, int return_code);

// Forks management
int			ft_destroy_forks(int count_init, t_settings *settings);
int			ft_create_forks(int count, t_settings *settings);
void		ft_destroy_simulation(t_settings *settings);
int			ft_init_simulation(t_settings *settings);
void		ft_select_forks(t_philo *philos, t_settings *settings);

// Misc functions
int			ft_print_help(char *bin_name);
int			ft_misc_mutexes(t_settings *settings);

// Debug functions
void		ft_print_settings(t_settings *settings);
void		ft_verbose(char *message, char *file, int line);

// Simulation functions
int			ft_start_simulation(t_settings *settings);
long long	ft_timestamp(void);
void		*ft_life_cycle(void	*philosopher);
#endif