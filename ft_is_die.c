/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_die.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abechcha <abechcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 10:07:19 by abechcha          #+#    #+#             */
/*   Updated: 2024/03/01 10:21:47 by abechcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    ft_is_die(t_big *p)
{
    int i;

    while (p->is_all_eaten == 0 && p->flag_dead == 0)
    {
        i = 0;
        while (i++ < p->thread_num)
        {
            if (clock_now() - p->thread[i].time_of_last_meal > p->time_to_die)
            {   
                display_message(p->thread, "died");
                p->flag_dead = 1;
            }
        }
        if (p->flag_dead == 1)
            break ;
        i = 0;
        while (p->time_must_eat != -1 && i < p->thread_num)
            i++;
        if (i == p->thread_num)
            p->is_all_eaten = 1;
    }
}
