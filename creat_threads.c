/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abechcha <abechcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 09:27:45 by abechcha          #+#    #+#             */
/*   Updated: 2024/03/02 15:56:11 by abechcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    ft_is_eat(t_philo *p)
{
    pthread_mutex_lock(&(p->info->forks[p->fork_right]));
    display_message(p, "has taking a fork");
    pthread_mutex_lock(&(p->info->forks[p->fork_left]));
    display_message(p, "has taking a fork");
    display_message(p, "is eating");
    pthread_mutex_lock(&(p->info->eat));
    usleep(p->info->time_to_eat * 1000);
    p->meal_number++;
    p->time_of_last_meal = clock_now();
    pthread_mutex_unlock(&(p->info->eat));
    pthread_mutex_unlock(&(p->info->forks[p->fork_left]));
    pthread_mutex_unlock(&(p->info->forks[p->fork_right]));
}

int check_is_dead(t_big *ptr)
{
    pthread_mutex_lock(&(ptr->die));
    if (ptr->flag_dead == 0)
    {
        pthread_mutex_unlock(&(ptr->die));
        return (1);
    }
    pthread_mutex_unlock(&(ptr->die));
    return (0);
}

void *ft_life_circle(void *p)
{
    t_philo *ptr;
    t_big   *big;
    ptr = (t_philo *)p;
    big = ptr->info;
    if (big->thread->philo_id % 2 == 0)
       sleep(1);
    while(check_is_dead(big) == 1)
    {
        if (big->thread_num == 1)
        {
            display_message(p, "has taking a fork");
            break ;
        }
        if (big->is_all_eaten == 1)
            break ;
        ft_is_eat(ptr);
        display_message(p, "is sleeping");
        usleep(big->time_to_sleep * 1000);
        display_message(p, "is thinking");
    }
    return NULL;    
}

void ft_creat_threads(t_big *p)
{
    int i;

    i = 0;
    p->start_prg = clock_now();
    while(i < p->thread_num)
    {
        if (pthread_create(&(p->thread[i].thread_philo), NULL, ft_life_circle, &(p->thread[i])) != 0)
            ft_error(1);
        i++;
    }
}