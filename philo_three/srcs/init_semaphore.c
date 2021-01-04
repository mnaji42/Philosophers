/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_semaphore.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaji <mnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 22:37:03 by najimehdi         #+#    #+#             */
/*   Updated: 2020/02/16 14:19:46 by mnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

static int	free_init_semaphore_loop(t_sem *s, int i)
{
	sem_unlink("fork");
	sem_unlink("write");
	while (i-- > 0)
	{
		sem_unlink(s->eat_name[i]);
		free(s->eat_name[i]);
		s->eat_name[i] = NULL;
	}
	free(s->eat_name);
	s->eat_name = NULL;
	free(s->eat);
	s->eat = NULL;
	return (0);
}

static int	free_init_semaphore(t_sem *s, int step)
{
	if (step == 1)
		sem_unlink("fork");
	else if (step == 2)
	{
		sem_unlink("fork");
		sem_unlink("write");
	}
	else if (step == 3)
	{
		sem_unlink("fork");
		sem_unlink("write");
		free(s->eat_name);
		s->eat_name = NULL;
	}
	return (0);
}

static int	init_semaphore_loop(t_sem *s, t_param p)
{
	int		i;

	i = 0;
	while (i < p.nb_philo)
	{
		if (!(s->eat_name[i] = ft_strdup("eat")))
			return (free_init_semaphore_loop(s, i));
		if (!(s->eat_name[i] = ft_strjoin_free(s->eat_name[i], \
			s->eat_name[i], ft_itoa(i))))
			return (free_init_semaphore_loop(s, i + 1));
		sem_unlink(s->eat_name[i]);
		if (!(s->eat[i] = sem_open(s->eat_name[i], O_CREAT, S_IRWXU, 1)) \
			|| s->eat[i] == SEM_FAILED)
			return (free_init_semaphore_loop(s, i + 1));
		s->eat[i] = sem_open(s->eat_name[i], 0);
		i++;
	}
	return (1);
}

int			init_semaphore(t_sem *s, t_param p)
{
	sem_unlink("fork");
	sem_unlink("write");
	if (!(s->forks = sem_open("fork", O_CREAT, S_IRWXU, p.nb_philo)))
		return (0);
	s->forks = sem_open("fork", 0);
	if (s->forks == SEM_FAILED)
		return (0);
	if (!(s->write = sem_open("write", O_CREAT, S_IRWXU, 1)))
		return (free_init_semaphore(s, 1));
	s->write = sem_open("write", 0);
	if (s->write == SEM_FAILED && sem_unlink("fork"))
		return (0);
	if (!(s->eat_name = (char**)ft_memalloc(sizeof(char*) * (p.nb_philo))))
		return (free_init_semaphore(s, 2));
	if (!(s->eat = (sem_t**)ft_memalloc(sizeof(sem_t*) * (p.nb_philo))))
		return (free_init_semaphore(s, 3));
	if (!init_semaphore_loop(s, p))
		return (0);
	return (1);
}
