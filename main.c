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
    pthread_mutex_destroy(&(p->print_____message));
    pthread_mutex_destroy(&(p->eat____));
    pthread_mutex_destroy(&(p->die));
    pthread_mutex_destroy(&(p->all_eat));
    pthread_mutex_destroy(&(p->meal________number));
    free (p->thread);
    free (p->forks);
}

void	init____mutex(t_big *prg)
{
	int	i;

	i = -1;
	prg->forks = malloc(sizeof(pthread_mutex_t) * prg->thread_num);
	if (!(prg->forks))
		return;
	while (++i < prg->thread_num)
		if (pthread_mutex_init(&(prg->forks[i]), NULL))
			return;
	if (pthread_mutex_init(&(prg->print_____message), NULL))
		return;
	if (pthread_mutex_init(&(prg->eat____), NULL))
		return;
	if (pthread_mutex_init(&(prg->die), NULL))
		return;
	if (pthread_mutex_init(&(prg->all_eat), NULL))
		return;
	if (pthread_mutex_init(&(prg->meal________number), NULL))
		return;
}

void	init____philosopher(t_big *prg)
{
	int	i;

	i = -1;
	prg->thread = malloc(sizeof(t_philo) * prg->thread_num);
	if (!(prg->thread))
		return ;
	while (++i < prg->thread_num)
	{
		prg->thread[i].fork_right = (i + 2) % prg->thread_num;
		prg->thread[i].meal_number = 0;
		prg->thread[i].info = prg;
        prg->thread[i].time_end_each_philo = 0;
		prg->thread[i].time_of_last_meal = 0;
		prg->thread[i].philo_id = i + 1;
		prg->thread[i].fork_left = i + 1;
	}
}

void	init____infos(t_big *prg, char **av)
{
	prg->thread_num = ft_atoi(av[1]);
	prg->time_to_die = ft_atoi(av[2]);
	prg->time_to_eat = ft_atoi(av[3]);
	prg->time_to_sleep = ft_atoi(av[4]);
	prg->is_all_eaten = 0;
	prg->flag_dead = 0;
	if (av[5])
		prg->time_must_eat = ft_atoi(av[5]);
	else
		prg->time_must_eat = -1;
}

int main (int ac , char **av)
{
    t_big   p;
    if (!(ac == 6 || ac == 5))
        return (-1);
    // BDEL HADCHI KIFMA BGHITI MS YKON M9AD W KHDAM
    // HADCHI HZITO MEN EENDI BASH NTESTI BIIIH BELA PARSING
    init____infos(&p, av);
    init____mutex(&p);
    init____philosopher(&p);

    // HADCHI MAT9ISOCH RA KHDAAAAAAM
    // MAT9ISSSSSSOCH
    ft_creat_threads(&p);
    ft_is_die(&p, (p.thread));
    free_all(&p);
    return 0;
}
