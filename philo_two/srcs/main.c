/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaji <mnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 01:55:24 by mnaji             #+#    #+#             */
/*   Updated: 2020/02/16 14:17:27 by mnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

static t_philo	*init_philo(t_sem *s, t_param *p, int i)
{
	t_philo *ph;
	int		j;

	j = 0;
	if (!(ph = (t_philo*)ft_memalloc(sizeof(t_philo) * p->nb_philo)))
	{
		sem_unlink("fork");
		sem_unlink("write");
		while (j < p->nb_philo)
			free(s->eat_name[j++]);
		free(s->eat_name);
		s->eat_name = NULL;
		free(s->eat);
		s->eat = NULL;
		return (0);
	}
	while (i < p->nb_philo)
	{
		ft_bzero(&ph[i], sizeof(t_philo));
		ph[i].last_eat = get_time_in_ms();
		ph[i].n = i + 1;
		ph[i].p = p;
		ph[i++].s = s;
	}
	return (ph);
}

static int		parse_param(t_param *p, char **argv)
{
	int		i;

	i = 0;
	p->time_must_eat = -1;
	p->nb_philo = ft_atoi(argv[++i]);
	p->time_die = ft_atoi(argv[++i]);
	p->time_eat = ft_atoi(argv[++i]);
	p->time_sleep = ft_atoi(argv[++i]);
	p->is_dead = 0;
	if (argv[++i])
		if ((p->time_must_eat = ft_atoi(argv[i])) < 0)
			return (0);
	if (p->nb_philo < 1 || p->time_die < 0 || p->time_eat < 0 \
		|| p->time_sleep < 0)
		return (0);
	p->start = get_time_in_ms();
	return (1);
}

int				main(int argc, char **argv)
{
	t_sem	s;
	t_param p;
	t_philo	*ph;

	ph = NULL;
	if (argc == 5 || argc == 6)
	{
		if (!parse_param(&p, argv))
			return (print_error("parsing\n", 1));
		if (!init_semaphore(&s, p))
			return (print_error("initialisation semaphore\n", 1));
		if (!(ph = init_philo(&s, &p, 0)))
			return (print_error("initialisation philosophers\n", 1));
		philo(ph);
		free_all(ph);
	}
	else
		ft_putstr("Usage: ./philo_one number_of_philosophers time_to_die "
			"time_to_eat time_to_sleep "
			"[number_of_times_each_philosopher_must_eat]\n");
	return (1);
}
