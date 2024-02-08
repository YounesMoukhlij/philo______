#ifndef PHILO_H
#define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_philo
{
    int philo_num;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int time_must_eat;
} t_philo;

int ft_is_digits(char *str);
long ft_atoi(char *str);
void ft_error(int f);
#endif