/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abechcha <abechcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 09:27:52 by abechcha          #+#    #+#             */
/*   Updated: 2024/03/02 15:59:46 by abechcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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


void    free_all(t_big *p)
{
    int i;

    i = 0;
    while(i++ < p->thread_num)
        pthread_join(p->thread[i].thread_philo , NULL);
    i = 0;
    while (i++ < p->thread_num)
        pthread_mutex_destroy(&(p->forks[i]));
    pthread_mutex_destroy(&(p->message));
    pthread_mutex_destroy(&(p->eat));
    free (p->thread);
    free (p->forks);
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
    ft_is_die(&p);
    free_all(&p);
    return 0;
}