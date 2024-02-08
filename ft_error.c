#include "philo.h"

void ft_error(int f)
{
    if (f == 1)
        write(1, "Error\n", 6);
    exit(1);
}