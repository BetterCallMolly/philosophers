NAME=philo
CC=cc
CFLAGS= -pthread -fsanitize=address -Wall -Werror -Wextra -D DEBUG=0
RM = rm -f

SRCS = utils/destroy_simulation.c \
	utils/ft_atoi.c \
	utils/ft_bzero.c \
	utils/ft_create_forks.c \
	utils/ft_error.c \
	utils/ft_init_simulation.c \
	utils/ft_misc_mutexes.c \
	utils/ft_putchar.c \
	utils/ft_putendl.c \
	utils/ft_putnbr.c \
	utils/ft_putstr.c \
	utils/ft_select_forks.c \
	utils/ft_strlen.c \
	utils/print_help.c \
	simulation/check_state.c \
	simulation/eat.c \
	simulation/log.c \
	simulation/micro_sleep.c \
	simulation/refree.c \
	simulation/routine.c \
	simulation/start.c \
	simulation/time.c \
	parse/ft_lint.c \
	parse/ft_parse.c \
	debug/print_settings.c \
	debug/verbose_print.c \
	main.c \

OBJS = $(SRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re