/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_element.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abechcha <abechcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 09:27:33 by abechcha          #+#    #+#             */
/*   Updated: 2024/02/29 16:37:21 by abechcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_set_element(t_big *p, int *ar)
{
    int i = 0;

    while(i < 4)
    {
        if (ar[i] == 0)
            ft_error(1);
        i++;
    }
    p->thread = malloc(sizeof(t_philo) * p->thread_num);
    if (!p->thread)
        return ;
    p->forks = malloc(sizeof(pthread_mutex_t) * p->thread_num);
    if (!p->forks)
        return ;
    p->time_to_die = ar[1];
    p->time_to_eat = ar[2];
    p->time_to_sleep = ar[3];
    p->time_must_eat = ar[4];
    p->thread_num = ar[0];
    p->flag_dead = 0;
    p->is_all_eaten = 0;

    pthread_mutex_init(p->forks, NULL);

    i = 0;
    while(i <= p->thread_num)
    {
        p->thread[i-1].philo_id = i;
        p->thread[i-1].fork_left = i;
        p->thread[i-1].fork_right = (i + 1) % p->thread_num;
        p->thread[i-1].meal_number = 0;
        p->thread[i-1].time_of_last_meal = 0;
        p->thread[i-1].info = p;
        i++;
    }
}
