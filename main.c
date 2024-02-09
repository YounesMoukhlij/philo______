#include "philo.h"

int ft_is_digits(char *str)
{
    int i = 0;
    long s = ft_atoi(str);
    while (str[i])
    {
        while((str[i] && str[i] == 32 )|| (str[i] <= 13 && str[i] >= 9))
            i++;
        if (str[i] == '+')
            i++;
        if (str[i] >= '0' && str[i] <= '9')
            i++;
        else
            return 0;
    }
    if (s > 2147483647)
        return 0;
    return 1;
}
int main (int ac , char **av)
{
    int i = 1;
    t_big   p;
    int ar[5];
    int j = 0;
    if (ac == 6 || ac == 5)
    {
        while(i <= ac -1)
        {
            if (ft_is_digits(av[i]))
                ar[j] = ft_atoi(av[i]);
            else
                ft_error(1);
            i++;
            j++;
        }
        if (ac == 5)
            ar[j] = -1;
    }
    else 
        ft_error(1);
    ft_set_element(&p, ar);
    ft_creat_threads(&p);
    // i = 0;
    // while(i < ar[0])
    // {
    //     printf("thred");
    //     printf("%d", i);
    //     printf("\ntime_to_die===>%d\n", p.thread[i].time_to_die);
    //     printf("time_to_eat===>%d\n", p.thread[i].time_to_eat);
    //     printf("time_to_sleep==>%d\n", p.thread[i].time_to_sleep);
    //     printf("time_must_eat==>%d\n", p.thread[i].time_must_eat);
    //     printf("-----------------------------------------\n");
    //     i++;
    // }
}