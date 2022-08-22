# 💭 Philosophers

![Coded in C](https://img.shields.io/badge/language-C-blue?style=flat-square)
![100](https://img.shields.io/badge/grade-100-success?style=flat-square)
![Norm V3 compatible](https://img.shields.io/badge/norm-OK-brightgreen?style=flat-square)
![No leaks](https://img.shields.io/badge/leaks-OK-brightgreen?style=flat-square)
![Project is finished](https://img.shields.io/badge/project%20state-Finished-success?style=flat-square)
![No bonuses](https://img.shields.io/badge/bonuses-NO-important?style=flat-square)
![No unit tests are available](https://img.shields.io/badge/unit%20tests-NO-red?style=flat-square)


Difficulty level : 💢💢⚫⚫⚫

Coolness : ✨✨✨⚫⚫

## 🧮 Authorized functions

|        Function       |                                                                         Brief summary                                                                         |
|:---------------------:|:-------------------------------------------------------------------------------------------------------------------------------------------------------------:|
|         memset        |                                                            fill `n` bytes of a memory area with `x`                                                           |
|         printf        |                                                                    display stuff on stdout                                                                    |
|         malloc        |                                                                  allocate `n` bytes of memory                                                                 |
|          free         |                                                            free a pointer allocated using `malloc`                                                            |
|         write         |                                                                write `n` bytes to a file descriptor                                                                |
|         usleep        |                                                          sleep in current thread for `n` microseconds                                                         |
|      gettimeofday     |                                                     get current time in a timezone (default: system time)                                                     |
|     pthread_create    |                                                          spawn a thread, that runs a passed function                                                          |
|     pthread_detach    | set a thread's state to `detached`, freeing its ressources when its execution is finished <br /> (⚠️ `detached` threads CANNOT be synchronized with any other thread) |
|      pthread_join     |                                             block calling routine until the passed thread is done with its routine                                            |
|   pthread_mutex_init  |                                           create a mutex that will be used to block memory areas to avoid data races                                          |
| pthread_mutex_destroy |                                                                    destroy cleanly a mutex                                                                    |
|   pthread_mutex_lock  |  lock a mutex, preventing any other lock using `pthread_mutex_lock` until mutex is unlocked <br /> (⚠️ blocks other calls to `pthread_mutex_lock` on the same mutex) |
|  pthread_mutex_unlock |                                                                         unlock a mutex                                                                        |

## Missing things for perfection

- Calls to `pthread_mutex_lock` and `pthread_mutex_unlock` **aren't protected** and might cause unwanted behavior
- Call to `gettimeofday` **isn't protected** and might cause unwanted behavior
- `memset` **should** be use instead of `ft_bzero` for faster initialization (and for the sake of it)
- `DEBUG` flag isn't used very often, and be used for a more efficient debugging
- Neither `MMD` nor `I` flags are used with `cc` in the Makefile

## 📊 Miscellaneous statistics

| File                 | Lines | Size      |
|----------------------|-------|-----------|
| colors.h             | 271   | 10.15 KB  |
| philosophers.h       | 100   | 3.73 KB   |
| ft_lint.c            | 60    | 2.56 KB   |
| refree.c             | 56    | 2.59 KB   |
| start.c              | 56    | 2.29 KB   |
| ft_parse.c           | 55    | 2.57 KB   |
| eat.c                | 50    | 2.32 KB   |
| ft_misc_mutexes.c    | 49    | 2.40 KB   |
| ft_atoi.c            | 47    | 1.80 KB   |
| ft_init_simulation.c | 47    | 2.13 KB   |
| ft_create_forks.c    | 43    | 1.92 KB   |
| log.c                | 40    | 2.19 KB   |
| routine.c            | 34    | 1.60 KB   |
| ft_select_forks.c    | 34    | 1.70 KB   |
| print_help.c         | 31    | 1.52 KB   |
| check_state.c        | 29    | 1.52 KB   |
| micro_sleep.c        | 29    | 1.38 KB   |
| main.c               | 27    | 1.46 KB   |
| print_settings.c     | 24    | 1.40 KB   |
| destroy_simulation.c | 24    | 1.45 KB   |
| ft_putnbr.c          | 24    | 1.21 KB   |
| ft_bzero.c           | 20    | 1.05 KB   |
| ft_error.c           | 20    | 1.17 KB   |
| time.c               | 18    | 1.10 KB   |
| ft_strlen.c          | 17    | 991.00 B  |
| verbose_print.c      | 16    | 1.04 KB   |
| ft_putendl.c         | 15    | 1.00 KB   |
| ft_putchar.c         | 14    | 1006.00 B |
| ft_putstr.c          | 14    | 1.01 KB   |
